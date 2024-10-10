#include <iostream>
#include <string>
#include <utility>
using namespace std;

// 1. Function that multiplies two numbers
int multiply(int a, int b) {
    return a * b;
}

// 2. Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// 3. Function that takes a string and splits it into two
std::pair<std::string, std::string> splitString(const std::string& s) {
    int mid = s.length() / 2;
    return std::make_pair(s.substr(0, mid), s.substr(mid));
}

// 4. Function to test pass-by-reference or pass-by-value
void modifyValue(int& a) {
    a = 520;  // This will modify the value to 520.
}

int main() {
    // 1. Call the multiply function
    int result1 = multiply(5,8); 
    cout << "Multiply result: " << result1 << endl;
    
    // 2. Call the recursive factorial function
    int result2 = factorial(5);
    cout << "Factorial result: " << result2 << endl;
    
    // 3. Call the split string function
    pair<string, string> result3 = splitString("HelloWorld");
    cout << "Split result: " << result3.first << " | " << result3.second << endl;
    
    // 4. Call the pass-by-reference function
    int num = 100;
    modifyValue(num);
    cout << "Modified value: " << num << endl;

    return 0;
}
