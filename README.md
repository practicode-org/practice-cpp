# Practice C++
Practice C++ by solving well-prepared exercises.

Complexity level is middle. Not "how to write a for loop and push to a vector", but rather questions like efficient sorting, concurrency and advanced use of STL.

C++ compiler: any C++17 compliant.

Build system: CMake 3.19+.

OS: Tested on `Manjaro Linux x86_64`, support for other platforms is desired.

Contribution is appreciated, please read the [guide](CONTRIBUTING.md).

## How to build
```
git submodule update --recursive --init
cd exercises
cmake -Bbuild .
cmake --build build
```
