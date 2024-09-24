#include <iostream>
#include <string>
#include <map>

int main() {
    // Integer
    int myInt = 50;
    
    // String
    std::string myString = "Hello";

    // Float number
    float myFloat = 2.14;

    // Boolean
    bool isTrue = true;

    // Array
    int myArray[3] = {1, 2, 3};

    // Dictionary
    std::map<std::string, int> myMap;
    myMap["apple"] = 10;
    myMap["banana"] = 20;

    // ---- Operations ----
     
    // Adding int and float
    float sum = myInt + myFloat;  // Result is a float
    std::cout << "Sum of int and float: " << sum << std::endl;

    // Division 
    int division1 = myInt / 5;  
    float division2 = myInt / 5.0; 
    std::cout << "Integer division: " << division1 << std::endl;
    std::cout << "Mixed division (int/float): " << division2 << std::endl;

    // Conversions
    // Int to float
    float convertedFloat = myInt;  // 50 becomes 50.0
    std::cout << "Converted int to float: " << convertedFloat << std::endl;

    // String to int
    std::string numStr = "100";
    int convertedInt = std::stoi(numStr);  // Convert string to int
    std::cout << "Converted string to int: " << convertedInt << std::endl;

    // Boolean operations
    bool comparison = myInt > 40;
    std::cout << "Is myInt greater than 40? " << comparison << std::endl;

    // ---- Arrays and Lists ----
    std::cout << "Array elements: ";
    for (int i = 0; i < 3; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // ---- Dictionary Operations ----
    std::cout << "Map elements:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
