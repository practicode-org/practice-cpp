#include <cstdint>
#include <ctime>
#include <iostream>
#include <iomanip>

void printTime(std::time_t secondsSinceEpoch) {
  std::cout << "Local time is: " << std::put_time(std::localtime(&secondsSinceEpoch), "%c %Z") << std::endl;
}
