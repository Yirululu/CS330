# CS330 -- Yiru
This repo is for learning C++ in Programming Languages\
Author: Yiru Chen

## Language quick overview
**C++ is a popular programming language. And is used to create computer programs, and is one of the most used language in game development.C++ allows software developers to define their own data types and manipulate them using functions and methods. It also allows low-level programming and provides access to memory, enabling fast and efficient execution of code. It also supports generic programming using templates, which let code be written in a generic form and reused for different data types.\
The C++ language is an object-oriented programming languages and is a Middle-Level Language. It is used in fields such as system software, game development, embedded systems, scientific computing and high-performance applications. The C++ standard library provides a range of coding utilities and functions, making it easy to develop complex software systems. C++ can run on many platforms, including Linux, Mac and Windows.**

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
Write a simple C++ program, for example the "Hello World"(I also provided the code as a seperate file [file](https://github.com/Yirululu/CS330/blob/main/Helloworld.cpp):
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
Refer to the [file]( ) for code samples
### Naming
#### Case Sensitive
C++ is case-sensitive, for example, newNum and newnum are totally different identifiers in C++.
#### Starting character
Variable name must start with a letter (A-Z or a-z) or an underscore (_), but cannot start with a digit. And names cannot contain special symbols except underscore (_).
#### Style conventions:
Camel case is common for local variables (newNum).\
Underscore case: Sometimes used, especially in constants (such as first_name).








## Sources
[1]https://www.geeksforgeeks.org/history-of-c/ \
[2]https://www.w3schools.com/cpp/ \
[3]https://www.techtarget.com/searchdatamanagement/definition/C#:~:text=C%2B%2B%20is%20used%20in%20fields,to%20develop%20complex%20software%20systems/ \
[4]https://www.youtube.com/watch?v=Qw5qjRNlC-Y \
[5]https://code.visualstudio.com/docs/languages/cpp \
[6]https://www.ibm.com/docs/en/i/7.4?topic=only-name-binding-dependent-names-c \
[7]





