/*
Task:
- change a `wait` call with an external condition to a `wait_for` call.
*/
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool event_happened = false;

using namespace std::chrono_literals;

void receiver_thread() {
  for (int i = 0; i < 2; i++) {
    std::unique_lock<std::mutex> l(mtx);
    // TODO: here ↓↓↓
    while (!event_happened) {
      cv.wait(l);
      std::cout << "thread: woke up" << std::endl;
    }
  }
  std::cout << "thread: event received" << std::endl;
}

void sender() {
  std::this_thread::sleep_for(1ms); // for sake of the exercise: make sure another thread has started waiting
  {
    std::unique_lock<std::mutex> l(mtx);
    cv.notify_one();
  }

  std::cout << "main: notified without a real event" << std::endl;
  std::this_thread::sleep_for(1s);

  {
    std::unique_lock<std::mutex> l(mtx);
    event_happened = true;
    cv.notify_one();
  }
  std::cout << "main: event sent" << std::endl;
}

int main() {
  std::thread t(receiver_thread);
  sender();
  t.join();
  return 0;
}
