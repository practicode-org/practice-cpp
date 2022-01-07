# Practice C++
Practice middle/senior C++ by solving well-prepared exercises.

C++ compiler: any C++17 compliant.

Build system: CMake 3.19+.

OS: Tested on `Manjaro Linux x86_64`, support for other platforms is desired.

## How to build
```
git submodule update --recursive --init
cd exercises
cmake -Bbuild .
cmake --build build
```
