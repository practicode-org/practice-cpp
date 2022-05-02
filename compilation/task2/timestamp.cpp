#include <cstdint>
#include <ctime>

std::time_t getPosixTimeSec() {
  return time(nullptr);
}
