# Practice C++
Practice C++ by solving well-prepared exercises! Complexity level is middle. Not "how to write a for loop and push to a vector", but rather questions like efficient sorting, concurrency, and advanced use of STL. There's no linear path, and you can choose any topic you're interested in. The project is mostly for advanced juniors and middle software engineers interested in acquiring deep C++ knowledge. Nevertheless, a senior developer may want to recall a particular topic too.

C++ compiler: any C++17 compliant.

Build system: CMake 3.19+.

OS: Tested on `Manjaro Linux x86_64`, support for other platforms is desired.

## Getting started
```
git clone https://github.com/practicode-org/practice-cpp
cd practice-cpp
git submodule update --recursive --init
cd exercises
cmake -Bbuild .
cmake --build build
```
Now open any .cpp task you'd like to start with, tinker with it, recompile with `cmake --build build`, try and repeat, until it's done.

## How to use it
1. Before starting, make sure you:
- understand the task description, constrains and examples
- compile the program (unless the task is to fix compilation) and run it
- see that the current program, output or behavior is not correct
- understand what behavior is expected and how you would check for correctness
- write some unit tests (if applicable)

2. You can use StackOverflow, but understand what you copy. And next time you have the same subtask, try to recall and write by yourself.

3. How to check if you are correct:
- code compiles
- you ran it multiple times with a predictable, stable, successful result
- tests pass, no sign of errors in the output
- you can verify results, and they match your expectations
- watch for "self-check" sections in exercises' descriptions
- optional: sanitizers show no errors
- ask somebody for a code review if you are still unsure

4. There's no sense in cheating: there is no competition (except with yourself) and there are no prizes.

5. If you need help, you can ask for it in the [public tlk chat](https://tlk.io/practicode-cpp) (altough it may feel deserted).

## Contribution
Contribution is appreciated, please, read the [guide](CONTRIBUTING.md).
