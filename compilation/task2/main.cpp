#include <cstdint>
#include <ctime>

extern std::time_t getPosixTimeSec();
extern void printTime(std::time_t secondsSinceEpoch);

int main() {
  auto time_sec = getPosixTimeSec();
  printTime(time_sec);
  return 0;
}
