# Task 1
1) Compile a shared library (.so file) and a program that dynamicly loads it.

The shared library consists of:
- print_time.cpp
- timestamp.cpp

The program:
- main.cpp
- loads the shared library

2) Execute the compiled binary. You might also need to do a few steps here.

3) Study the compiled binary with `ldd` and notice that it depends on the library.
Study the shared libarary and find exported functions `getPosixTimeSec` and `printTime`.
Find their assembly code with `objdump`.

