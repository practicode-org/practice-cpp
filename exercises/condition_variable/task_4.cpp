/*
Task:
- write a thread-safe queue (with use of condition_variable) and tests for it.
*/
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>

template <typename T>
class Queue {
 public:
  Queue(int max_queue_len) {}

  void enqueue(const T& value) {}

  T pop() {}

 private:
  // underlying data type
  std::queue<T> storage;
};

int main() {
  return 0;
}
