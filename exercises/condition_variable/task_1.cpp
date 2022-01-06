/*
C++ concurrency: condition_variable

Task:
- Rewrite how data is passed between threads. Use condition_variable.
- Add an exit condition. When a producer thread finished its work, wait around 1ms and send exit signal to the consumer
thread.

Self-check:
- `condition_variable` is used.
- Task-receiver is not busy all the time in a loop, but go to sleep when there are no tasks.
- `tsan` shows no errors.
*/
#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::mutex mtx;
std::queue<int> queue;

void do_task(int task) {
  std::string s = "task " + std::to_string(task) + " completed";
  std::cout << s << std::endl;
}

void task_producer_func() {
  for (int i = 0; i < 16; i++) {
    std::this_thread::sleep_for(std::chrono::microseconds(rand() % 100));
    std::unique_lock l(mtx);
    queue.push(i + 1);
  }
}

void task_receiver_func() {
  while (true) {
    // get a task
    int task = 0;
    while (true) {
      std::unique_lock l(mtx);
      if (!queue.empty()) {
        task = queue.front();
        queue.pop();
        break;
      }
    }

    do_task(task);
  }
}

int main() {
  std::thread task_receiver_thread(task_receiver_func);

  std::thread task_producer_thread(task_producer_func);
  task_producer_thread.join();

  task_receiver_thread.join();
  return 0;
}
