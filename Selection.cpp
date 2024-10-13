#include <iostream>
using namespace std;

int main() {
    
    // One-condition if/else
    int x = 10;
    if (x == 10) {
        cout << "x is 10\n";
    } else {
        cout << "x is not 10\n";
    }

    // Multi-condition if/else
    int y = 20;
    if (x > 0 && y < 50) {
        cout << "x is positive and y is less than 50\n";
    }

    // if/elif/else (if, else if, else in C++)
    if (x == 1) {
        cout << "x is 1\n";
    } else if (x == 2) {
        cout << "x is 2\n";
    } else {
        cout << "x is something else\n";
    }

    // Short-circuit logic
    int a = 0, b = 5;
    if (a != 0 && b / a > 1) {
        // Won't execute, short-circuit prevents division by zero
        cout << "This won't print\n";
    }

    // Switch-case statement
    switch (x) {
        case 1:
            cout << "x is 1\n";
            break;
        case 5:
            cout << "x is 5\n";
            break;
        default:
            cout << "x is something else\n";
    }

    // Loops
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    int i = 0;
    while (i < 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    i = 0;
    do {
        cout << i << " ";
        i++;
    } while (i < 5);
    cout << endl;

    return 0;
}
