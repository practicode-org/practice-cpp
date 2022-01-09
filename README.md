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

## Contribution
Contribution is appreciated, please, read the [guide](CONTRIBUTING.md).
