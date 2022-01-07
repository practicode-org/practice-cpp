/*
Task:
- call the `func` function 10000 times, record function runtime durations, and find minimum, maximum, average, mean, 90-th percentile duration.
- print it in microseconds and nanoseconds.

plus: print in floating point number of seconds and milliseconds.
*/
#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono_literals;

void func() {
  std::this_thread::sleep_for(0.5ms);
}

int main() {
  func();
  return 0;
}
