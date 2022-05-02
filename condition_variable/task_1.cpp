/*
Task:
- Replace a busy wait with a condition_variable.

Self-check:
- Atomic bool is not used, condition_variable is used.
- Another thread gets the signal, the program finishes.
- Thread-sanitizer reports no errors.
*/
#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <atomic>

std::atomic_bool resume;

void another_thread_func() {
  while (!resume.load()) {
  }

  std::cout << "another thread: got the signal and resumed" << std::endl;
}

int main() {
  std::thread t(another_thread_func);

  std::cout << "main: signalling the other thread to resume" << std::endl;

  // TODO: replace with a condition_variable
  resume.store(true);

  t.join();
  return 0;
}
