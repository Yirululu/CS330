# CS330 -- Yiru
This repo is for learning C++ in Programming Languages\
Author: Yiru Chen

## Language quick overview
C++ is a popular programming language. And is used to create computer programs, and is one of the most used language in game development.C++ allows software developers to define their own data types and manipulate them using functions and methods. It also allows low-level programming and provides access to memory, enabling fast and efficient execution of code. It also supports generic programming using templates, which let code be written in a generic form and reused for different data types.\
The C++ language is an object-oriented programming languages and is a Middle-Level Language. It is used in fields such as system software, game development, embedded systems, scientific computing and high-performance applications. The C++ standard library provides a range of coding utilities and functions, making it easy to develop complex software systems. C++ can run on many platforms, including Linux, Mac and Windows.

### History
C++ was created in 1979 by Danish computer scientist Bjarne Stroustrup at AT&T Bell Labs.\
As he wanted a flexible & a dynamic language which was similar to C with all its features, but with additionality of active type checking, basic inheritance, default functioning argument, classes, inlining, etc. and hence C with Classes (C++) was launched.\
It originated from analysis of the UNIX kernel to investigate to what extent it can be distributed over a network.\

### Getting Started
#### How to use C++?
To start programming in C++, I will choose to use Visual Studio Code as a good programming environment. Because Visual Studio Code includes an interactive debugger, so you can step through source code, inspect variables, view call stacks, and execute commands in the console. VS Code also integrates with build and scripting tools to perform common tasks making everyday workflows faster. You can download Visual Studio Code from [here](https://code.visualstudio.com/) \
Also, developers need a C++ compiler that translates code into machine-readable instructions. Once a compiler is installed, developers can use a text editor or integrated development environment (IDE) to write C++ code. IDEs offer features such as code completion, debugging tools and management capabilities. I followed a video from Youtube about how to set up C++ on Vscode by eEmmFinity. You can also find the video link on the end of this post. And here is a step by step tutorial.

### Step-by-Step Guide: Setting Up C++ in VSCode on macOS:
If you’re planning to use Visual Studio Code (VSCode) for C++ development on a Mac, here’s a comprehensive guide to get you started:
#### 1. Install the Necessary Extensions
Open VSCode and go to the Extensions view by clicking the Extensions icon on the sidebar.\
Search for C/C++ and install the official Microsoft extension. This will enable C++ IntelliSense, code navigation, and debugging support.\
Next, install Code Runner. This handy extension allows you to quickly run code snippets without needing to manually compile and execute each time.
#### 2. Install Clang Compiler
Macs typically come with Clang pre-installed. To check if it’s installed, open Terminal and type:
```
clang --version
```
If Clang is install, the terminal will show like:
```
Apple clang version 15.0.0 (clang-1500.1.0.2.5)
Target: arm64-apple-darwin23.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```
Otherwise, to install the clang, type this in terminal: (if you already pre-installed, then just skip this)
```
xcode-select --install
```
Then, Clang acts as the C++ compiler that will turn your code into executable programs.
#### 3. Configure Code Runner for a Smooth Workflow
Once the extensions are installed, head over to Settings in VSCode.\
Search for Run Code Configuration.\
Check the boxes for:\
“Run In Terminal” (to execute code within the terminal for better interaction)\
“Save File Before Run” (to auto-save your code before each execution).
#### 4. Now you are ready to run your code!

### How to run your code in C++?
In VSCode, go to File > New Text File, then choose C++ as the language when prompted.\
Write a simple C++ program, for example the "Hello World"(I also provided the code as a seperate [file](https://github.com/Yirululu/CS330/blob/main/Helloworld.cpp):
```
#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!";
  return 0;
}
```
When running C++ in VSCode, there are two main methods you can use:

Run Code via Terminal:
Click the run (triangle/play) button at the top right corner of the screen.\
From the drop-down menu, then select "Run Code".\
This method runs your code and displays the output directly in the Terminal. It's a quick and simple way to see your results.\

Run Using Debug Console:
Select Run C/C++ file from the run button's drop-down.\
Then choose the option labeled C/C++: g++ build and debug active file.\
This will display output in the Debug Console, which is useful if you’re debugging the program.\

Try run the "Hello World" file in your VScode!!!

#### Write comments in C++
To write comments in C++, you can use: 
#### Single-line comments:
Use // to comment out a single line. Anything after // on that line is ignored by the compiler.\
To type this in VScode:
```
// This is a single line comment.
int x = 19; // You can also comment after the code.
```
#### Multi-line comments:
Use /* */ to create comments that span multiple lines. Everything between /* and */ is ignored by the compiler.\
To type this in VScode:
```
/* This is a 
   multi-line comment */
int y = 90;
```
## Names, Types and Binding
Refer to the [file](https://github.com/Yirululu/CS330/blob/main/variables.cpp) for code samples
### Naming
#### Case Sensitive
C++ is case-sensitive, for example, newNum and newnum are totally different identifiers in C++.
#### Starting character
Variable name must start with a letter (A-Z or a-z) or an underscore (_), but cannot start with a digit. And names cannot contain special symbols except underscore (_).
#### Style conventions:
Camel case is common for local variables (newNum).\
Underscore case: Sometimes used, especially in constants (such as first_name).

### Types
```
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
```

#### Statically or Dynamically?
C++ is a statically typed language, meaning the type of each variable is determined at compile time. 

#### Strongly typed or weakly typed?
It is strongly typed, and data is predefined within the language. So that type conversions must be explicit in most cases. 

#### Explicitly typed or implicitly typed?
C++ is explicit, it needs to declare variable types, function parameters, and return values before using them. Implicit 

#### Are some variables mutable while others are immutable?
By default, variables in C++ are mutable, meaning their values can change after being assigned. However, you can declare variables as immutable using the "const" keyword:
```
const int a = 80; // then x is changing to immutable.
```
#### Coding Example contains these features:
```
#include <iostream>

int main() {
    // Statically typed and mutable variable
    int a = 10;
    const float b = 3.14; // Immutable variable
    
    // Mixed-type operation
    float result = a + b; // 'a' is changing to float
    
    // Type binding and operator binding at compile time
    std::cout << "The result is: " << result << std::endl;
    
    // Example of implicit typing
    auto c = a * b; // 'c' is automatically a float due to mixed operation
    
    return 0;
}
```

### Operators
Operators | Symbols
--- | ---
C++ Arithmetic Operators | +, -, *, /, %
--- | ---
C++ Relational Operators| ==, !=, >, <, >=, <=
--- | ---
C++ Logical Operators | &&, ||, !
--- | ---
C++ Bitwise Operators | &, |, ^, ~, <<, >>
--- | ---
C++ Assignment Operators | =, +=, -=, *=, /=, %=


### Mixed-Type Operations
C++ allows mixed-type operations, but the results depend on type promotion rules. For example, if you add an int to a float, the int is promoted to float, and the result is a float. You can also use explicit type casting to ensure the correct type:
```
int x = 10;
float y = 3.14;
float result = x + y; // x change to float
```
## Functions
Refer to the [file](https://github.com/Yirululu/CS330/blob/main/Function.cpp) for code samples\
You can compile and run this code in any C++ IDE like VSCode, and it will display the results of each function call, proving how the language handles each task.

### Syntax for declaring a function
In C++, a function is declared with a return type, a name, and a list of parameters. For example, look at this code:
```
int multiply(int a, int b) {
    return a * b;
}
```
The return type 'int' comes before the function name 'multiply', followed by the parameters in parentheses. Parameters include both their types and names. 

### Function placement
In C++, functions must either be declared before they are used or be forward-declared. This is why all the functions in this code are written before the main() function.

### Recursive functions
C++ supports recursion, which is when a function calls itself. Here, the factorial function demonstrates this:
```
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
```
The base case stops the recursion when n is 0 or 1.

### Multiple parameters
C++ functions can accept multiple parameters, and they can be of different types. For example:
```
int multiply(int a, int b);
```
Here, both parameters are integers. If needed, different data types can be used in a single function.

### Returning multiple values
C++ does not natively return multiple values, but you can work around this using pair or tuple, or by using custom structs. In the splitString function, I use a pair to return two strings:
```
pair<string, string> splitString(string s) {
    int mid = s.length() / 2;
    return {s.substr(0, mid), s.substr(mid)};
}
```
### How are arguments passed to subprograms? 
C++ supports both pass-by-value and pass-by-reference. The modifyValue function demonstrates pass-by-reference using the & symbol:
```
void modifyValue(int& a) {
    a = 100;  // this modifies the original variable
}
```
When called, the original variable is modified, proving that it's pass-by-reference.

### Argument storage:
In C++, parameters passed by value are stored on the stack, while references are pointers to the heap memory. Local variables and parameters are usually stored in the stack frame of the current function.

### Scoping rules: 
Variables in C++ have block scope, meaning they are only visible within the block they are defined in. Function parameters and local variables are destroyed when the function exits, and their scope is limited to the function in which they are declared.

### Side-effects: 
Functions in C++ can cause side effects, particularly when using pass-by-reference. There are no guardrails against side effects unless you use const to prevent modification of passed variables.

### Local variable storage: 
Local variables are stored on the stack and dynamic objects are stored on the heap.

### Other considerations: 
C++ uses static scoping, meaning variable visibility is determined at compile time. Recursive functions should be used carefully to avoid stack overflow due to excessive recursion depth.


## Selection, Loops and Conditionals
Refer to the [file]() for code samples\

### Boolean Values in C++
In C++, the boolean values are true and false. They are part of the bool data type. Additionally, C++ allows using 1 for true and 0 for false. For example:
```
bool isTrue = true;
bool isFalse = false;
int a = 1;  // equivalent to true
int b = 0;  // equivalent to false
```

### Conditional Statements in C++
C++ supports ``if``, ``if/else`` statements. For example:
```
int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    // Using if statement
    if (number > 0) {
        cout << "The number is positive." << endl;
    }

    // Using if/else statement
    if (number < 0) {
        cout << "The number is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }

    return 0;
}
```
This program uses an if statement to check if the number is positive. Then, it uses an if/else statement to check if the number is negative; if it is not, it concludes that the number is zero. \
It demonstrates the basic structure and usage of conditional statements in C++.

### Code Block Delimitation
C++ uses curly braces ``{ }`` to delimit code blocks for conditional statements and loops. \
For example:
```
if (x > 0) {
    // code to execute
} else {
    // alternative code
}
```
### Short-Circuit Evaluation
C++ supports short circuit evaulation with ``&&`` (AND) ``||`` (OR) operators. \
Short-Circuit example:
```
int a = 0, b = 10;
if (a != 0 && b / a > 5) {
    // This will not cause a divide-by-zero error due to short-circuiting.
}
```
The && operator will not evaluate the second condition if the first one is false.

### Dangling Else problem
C++ resolves the "dangling else" problem by associating an ``else`` with the nearest ``if`` that does not already have an else branch. \
For example:
```
if (x > 0)
    if (y > 0)
        std::cout << "x and y are positive";
    else  // This 'else' is associated with the inner 'if'
        std::cout << "y is non-positive";
```

### Switch-Case Statement in C++
C++ supports ``switch-case`` statements. \
Break Statement: You must use ``break`` to prevent fall-through in each case. \ 
For example:
```
int x = 2;
switch (x) {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    default:
        std::cout << "Other";
}
```
Without ``break``, the cases will fall through, meaning that all statements after the matching case will be executed. And you cannot use ``continue`` in ``switch-case`` statements.

### Loop Types in C++
C++ supports several types of loops: \
``while`` loop: Repeats while a condition is True. For example:
```
int i = 0;
while (i < 5) {
    std::cout << i;
    i++;
}
```

``do-while`` loop: Executes at least once and then repeats based on a condition. For example:
```
int i = 0;
do {
    std::cout << i;
    i++;
} while (i < 5);
```

``for`` loop: Repeats a block of code a specific number of times.
```
for (int i = 0; i < 5; i++) {
    std::cout << i;
}
```

``range-based for`` loop: Iterates over elements in a container.
```
int arr[] = {1, 2, 3, 4};
for (int x : arr) {
    std::cout << x;
}
```
### Loop Code Block Variables
Variables declared inside a loop (or any code block) in C++ have *block scope*, meaning they are accessible only within that block. And variables declared inside a function (outside of loops) have *function scope* and are accessible throughout the function.



## Sources
[1]https://www.geeksforgeeks.org/history-of-c/ \
[2]https://www.w3schools.com/cpp/ \
[3]https://www.techtarget.com/searchdatamanagement/definition/C#:~:text=C%2B%2B%20is%20used%20in%20fields,to%20develop%20complex%20software%20systems/ \
[4]https://www.youtube.com/watch?v=Qw5qjRNlC-Y \
[5]https://code.visualstudio.com/docs/languages/cpp \
[6]https://www.ibm.com/docs/en/i/7.4?topic=only-name-binding-dependent-names-c \
[7]https://www.geeksforgeeks.org/early-binding-late-binding-c/ \
[8]https://cplusplus.com/doc/tutorial/functions/ \
[9]https://www.programiz.com/cpp-programming/function \
[10]https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-functions \
[11]https://learn.microsoft.com/en-us/cpp/cpp/functions-cpp?view=msvc-170 \
[12]https://stackoverflow.com/questions/20916162/calling-a-function-in-main \
[13]https://stackoverflow.com/questions/26588533/selection-and-iteration \
[14]https://www.programiz.com/cpp-programming/for-loop \
[15]https://cplusplus.com/doc/tutorial/control/ \
[16]https://cplusplus.com/forum/beginner/280810/ \
[17]https://www.geeksforgeeks.org/cpp-loops/ \







