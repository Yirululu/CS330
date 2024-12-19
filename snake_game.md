# Gluttonous Snake Game

**How to Use**

Assuming you have already installed the SFML library, follow these steps to compile and run the game:

1. Navigate to the `src` directory of the project and compile the code using the following command in your terminal:

   ```shell
   g++ -std=c++11 -o gluttonous_snake_game gluttonous_snake.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```
2. Once the code is successfully compiled, run the game with the following command:

   ```shell
   ./gluttonous_snake_game
   ```

## 1 Introduction

This project implements a **Snake Game** using **C++** and the **SFML library** in the **VSCode environment**. It combines object-oriented programming principles such as inheritance, polymorphism, and dynamic memory management to create a modular and maintainable codebase.

## 2 Core Features

### 2.1 Dynamic Object Management:

- The game dynamically manages objects like the **Snake** and **Food** using
  pointers, ensuring efficient memory usage.
  ```cpp
  // Create a new Snake object dynamically 
  Snake* snake = new Snake(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  ```
- It employs inheritance and polymorphism to design reusable and extendable
  classes, such as `GameObject` as the base class.
  ```c++
  // Base game object interface
  struct GameObject {
      virtual void draw(sf::RenderWindow& window) = 0;
  };
  ```

### 2.2 Gameplay Mechanics:

- A fully functional Snake game with:
  - Smooth movement: The snake moves across the grid with controlled speed.
  - Collision detection: The game ends when the snake collides with itself or the window boundaries.
  - Food mechanics: The snake grows and the score increases upon eating food.

### 2.3 Enhanced User Experience:

- Difficulty progression:
  - The snake's speed increases as the player's score rises, implemented through an exponential decay function to ensure a smooth and manageable challenge.
- High Score Module:
  - Tracks and saves the highest score across sessions, displayed prominently on the game interface.
- Game Start/Over Screens:
  - Features a visual start screen to initiate the game.
  - The game over screen displays the player's final score and the highest score, along with clear options to restart the game.

### 3 Project Details


#### About Font

SFML requires a font file to display text properly. In this project, we used a free font from [Google Fonts](https://fonts.google.com), stored in the `assets` folder.
You can replace it with any font of your choice.

```shell
assets/
└── Roboto-Regular.ttf
```

---

#### About Difficulty Adjustment

The snake's speed is adjusted dynamically based on the score using the following formula:

$$
speed=min\_mi + (init\_mi -  min\_mi) * e^{-decay\_rate*\frac{score}{100}}

$$

**Explanation of Parameters:**

- **speed**: The current speed of the snake.
- **init_mi**: The initial movement interval (defines how slow the snake moves at the start).
- **min_mi**: The minimum movement interval (defines the fastest speed the snake can achieve).
- **decay_rate**: The rate at which the speed increases (controls how quickly the snake accelerates as the score grows).
- **score**: The player's current score.

The formula ensures that the snake starts at the initial speed (`init_mi`), and as the score increases, the speed smoothly approaches the minimum speed (`min_mi`), controlled by the`decay_rate`.

**Speed Progression Table**

Here is an example of how the speed changes with different scores using the recommended parameters:

- assume we start from 0.3(initial) to 0.1(minimum)


| **score** | **speed** |
| ----------- | ----------- |
| 0         | 0.3       |
| 100       | 0.27      |
| 300       | 0.22      |
| 500       | 0.17      |
| 800       | 0.12      |
| 1000      | 0.1       |

You can control the speed by modifying the following parameters:

```cpp
// Speed control: lower MOVE_INTERVAL means faster movement
const float MOVE_INTERVAL = 0.3f; // Initial snake speed (Recommended: 0.2~0.3)
const float MIN_MOVE_INTERVAL = 0.1f; // Minimum snake speed (Recommended: 0.1)
const float DECAY_RATE = 0.3f; // Decay rate to control speed adjustment (Recommended: 0.2~0.4)

// Adjust speed based on the score
speed = MIN_MOVE_INTERVAL + (MOVE_INTERVAL - MIN_MOVE_INTERVAL) * std::exp(-DECAY_RATE * (score / 100));

// Ensure the speed does not drop below the minimum
speed = std::max(speed, MIN_MOVE_INTERVAL);
```

By tweaking these parameters, you can **customize the game's difficulty** and speed progression.
