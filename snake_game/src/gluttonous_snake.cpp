#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

// Constants for game dimensions and settings
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CELL_SIZE = 20;
// Control the speed, the lower MOVE INTERVAL the snake move faster
const float MOVE_INTERVAL = 0.3f; // Initial speed of the snake (Recommend: 0.2~0.3)
const float MIN_MOVE_INTERVAL = 0.1f; // The minimum speed (Recommend: 0.1)
const float DECAY_RATE = 0.3f; // Rate of decay (Control the speed, Recommend: 0.2~0.4)


const std::string HIGHSCORE_FILE = "assets/highscore.dat"; 

// Load high score from file
int loadHighScore() {
    std::ifstream file(HIGHSCORE_FILE);
    int highScore = 0;

    if (file.is_open()) {
        file >> highScore;  // Read the high score from the file
        file.close();
    }
    return highScore;
}

// Save high score to file
void saveHighScore(int highScore) {
    std::ofstream file(HIGHSCORE_FILE);
    if (file.is_open()) {
        file << highScore;  // Write the high score to the file
        file.close();
    }
}

// Base game object interface
struct GameObject {
    virtual void draw(sf::RenderWindow& window) = 0;
};

// A single segment of the snake
struct SnakeSegment : public GameObject {
    sf::RectangleShape shape;
    bool isHead; // Flag to determine if this segment is the head of the snake

    SnakeSegment(float x, float y, bool head = false) : isHead(head) {
        shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        shape.setFillColor(isHead ? sf::Color::Yellow : sf::Color::Green);
        shape.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
    }

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }
};

// Snake class that manages the snake's movement and state
class Snake {
public:
    std::vector<SnakeSegment*> body;
    sf::Vector2f direction;

    Snake(float x, float y) {
        body.push_back(new SnakeSegment(x, y, true)); // First segment is the head
        direction = sf::Vector2f(CELL_SIZE, 0);
    }

    // Destructor function
    // After this, the 'body' vector will still exist, but its contents will be deleted.
    // This ensures there are no memory leaks when the Snake object is destroyed.
    ~Snake() {
    // Iterate through the vector of SnakeSegment pointers
    for (auto segment : body) {
        // Free the memory allocated for each SnakeSegment
        delete segment;
        }
    }

    // Add a new segment to the snake's body
    void grow() {
        sf::Vector2f lastSegmentPos = body.back()->getPosition();
        body.push_back(new SnakeSegment(lastSegmentPos.x, lastSegmentPos.y));
    }

    // Update the state of the snake
    void move() {
        for (size_t i = body.size() - 1; i > 0; --i) {
            body[i]->setPosition(body[i - 1]->getPosition().x, body[i - 1]->getPosition().y);
        }
        sf::Vector2f currentHeadPos = body[0]->getPosition();
        body[0]->setPosition(currentHeadPos.x + direction.x, currentHeadPos.y + direction.y);
    }

    void draw(sf::RenderWindow& window) {
        for (auto segment : body) {
            segment->draw(window);
        }
    }

    bool checkCollision() {
        // Check if the snake's head collides with its body
        for (size_t i = 1; i < body.size(); ++i) {
            if (body[0]->getPosition() == body[i]->getPosition()) {
                return true;
            }
        }
        // Check if the snake's head collides with the walls (out of bounds)
        sf::Vector2f headPos = body[0]->getPosition();
        if (headPos.x < 0 || headPos.x >= WINDOW_WIDTH || headPos.y < 0 || headPos.y >= WINDOW_HEIGHT) {
            return true;
        }
        return false;
    }
};

// Food class that manage food's state
struct Food : public GameObject {
    sf::RectangleShape shape;

    Food() {
        shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        shape.setFillColor(sf::Color::Red);
        
    }

    // Reset the food's position, ensuring it does not overlap with the snake's body
    void resetPosition(const std::vector<SnakeSegment*>& snakeBody) {
        bool validPosition = false;
        while (!validPosition) {
            // Generate a random position for the food within the game window
            int x = (std::rand() % (WINDOW_WIDTH / CELL_SIZE)) * CELL_SIZE;
            int y = (std::rand() % (WINDOW_HEIGHT / CELL_SIZE)) * CELL_SIZE;

            validPosition = true;

            // Check if the generated position overlaps with any segment of the snake's body
            for (const auto& segment : snakeBody) {
                if (segment->shape.getPosition() == sf::Vector2f(x, y)) {
                    validPosition = false; 
                    break;
                }
            }

            // If the position is valid, set it as the new position for the food
            if (validPosition) {
                shape.setPosition(x, y);
            }
        }
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(shape);
    }
};

// Display text on the screen
void displayText(sf::RenderWindow& window, const std::string& text, int fontSize, float x, float y) {
    static sf::Font font; // Static ensures the font is only loaded once
    // Load the font
    if (!font.loadFromFile("assets/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }

    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(text);
    displayText.setCharacterSize(fontSize);
    displayText.setFillColor(sf::Color::White);
    displayText.setPosition(x, y);

    window.draw(displayText);
}




int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gluttonous Snake Game");
    // Limit frame rate to 60 FPS
    window.setFramerateLimit(60);

    std::srand(static_cast<unsigned>(std::time(nullptr)));

  

    // Load high score
    int highScore = loadHighScore();

    bool gameOver = false;
    bool inGame = false;
    Food food;
    int score = 0;
    float speed = MOVE_INTERVAL;
    sf::Clock moveClock; // Clock to control snake movement timing

    Snake* snake = new Snake(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    while (window.isOpen()) {
        sf::Event event;
        // Check the event queue and process any window events that occur (such as mouse clicks, key input, window closing, etc.).
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                // Start or restart the game when Enter is pressed
                if (event.key.code == sf::Keyboard::Enter) {
                    if (!inGame) {
                        inGame = true; // Enter the game
                    } else if (gameOver) {
                        gameOver = false;
                        // Update high score
                        if (score > highScore) {
                            highScore = score;      
                            saveHighScore(highScore);
                        }
                        delete snake;
                        snake = new Snake(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
                        score = 0;
                        speed = MOVE_INTERVAL;  // Reset speed
                        moveClock.restart(); // Reset movement clock
                    }
                }
            }
        }

        window.clear();

        if (!inGame) {
            // Display the start screen
            displayText(window, "Gluttonous Snake Game", 50, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 3);
            displayText(window, "Press Enter to Start", 30, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 2);
        } else if (gameOver) {
            // Update high score
            if (score > highScore) {
                highScore = score;      
                saveHighScore(highScore); 
            }
            // Display the game over screen
            displayText(window, "Game Over", 50, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 3);
            displayText(window, "Score: " + std::to_string(score), 30, WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2.1);
            displayText(window, "High Score: " + std::to_string(highScore), 30, WINDOW_WIDTH / 3, WINDOW_HEIGHT / 1.8);
            displayText(window, "Press Enter to Restart", 30, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 1.5);
        } else {
            // Gameplay logic
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake->direction.y == 0) {
                snake->direction = sf::Vector2f(0, -CELL_SIZE);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake->direction.y == 0) {
                snake->direction = sf::Vector2f(0, CELL_SIZE);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake->direction.x == 0) {
                snake->direction = sf::Vector2f(-CELL_SIZE, 0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake->direction.x == 0) {
                snake->direction = sf::Vector2f(CELL_SIZE, 0);
            }

            // Control snake movement frequency
            if (moveClock.getElapsedTime().asSeconds() >= speed) {
                snake->move();
                // Check if collision
                if (snake->checkCollision()) { 
                   
                    gameOver = true;
                }
                moveClock.restart();
            }

            // Check for food collision
            if (snake->body[0]->shape.getGlobalBounds().intersects(food.shape.getGlobalBounds())) {
                snake->grow();
                food.resetPosition(snake->body);
                score += 10;

               

                // Adjust speed based on score
                speed = MIN_MOVE_INTERVAL + (MOVE_INTERVAL - MIN_MOVE_INTERVAL) * std::exp(-DECAY_RATE * (score / 100));

                // Ensure speed does not drop below the minimum speed
                speed = std::max(speed, MIN_MOVE_INTERVAL);
            }

            // Draw game elements
            snake->draw(window);
            food.draw(window);

            // Display score and high score
            displayText(window, "Score: " + std::to_string(score), 20, 10, 10);
            displayText(window, "High Score: " + std::to_string(highScore), 20, 10, 40);
        }

        window.display();
    }

    delete snake;
    return 0;
}
