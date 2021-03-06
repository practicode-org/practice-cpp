/*
Task:
- call the `func` function 10000 times, record function runtime durations, and find minimum, maximum, average, mean,
90-th percentile duration.
- print it in microseconds and nanoseconds.

plus: print floating point number of seconds and milliseconds.
*/
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void func() {
  // do not change body of the function
  std::this_thread::sleep_for(0.5ms);
}

int main() {
  func();
  return 0;
}
