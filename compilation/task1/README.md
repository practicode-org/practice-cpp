# Task 1
Compile a program (using g++ or clang++) that consists of three translation units (three .cpp files) and execute it. The program prints current local time, which is handy.

The program will consists of source files:
- main.cpp
- print_time.cpp
- timestamp.cpp

Note: indeed there's no CMake for this task, as you need to do building manually.


# Task 2
The task is to build a program with use of a static library.

Static library 1:
- print_time.cpp
- timestamp.cpp

Program:
- main.cpp
- static library 1


# Task 3
Build a program with use of two static libraries.

Static library 1:
- timestamp.cpp

Static library 2:
- print_time.cpp

Program:
- main.cpp
- static library 1
- static library 2
