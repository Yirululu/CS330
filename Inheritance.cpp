#include <iostream>
#include <string>

// Base class: Vehicle
class Vehicle {
public:
    std::string brand;
    int year;

    Vehicle(std::string b, int y) : brand(b), year(y) {}

    virtual void showInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
public:
    int numDoors;

    Car(std::string b, int y, int d) : Vehicle(b, y), numDoors(d) {}

    void showInfo() const override {
        std::cout << "Brand: " << brand << ", Year: " << year 
                  << ", Doors: " << numDoors << std::endl;
    }
};

int main() {
    Vehicle vehicle("Toyota", 2010);
    vehicle.showInfo();

    Car car("Ford", 2022, 4);
    car.showInfo();
    return 0;
}
