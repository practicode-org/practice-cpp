/*
Task 1:
- sort strings by their length, not lexicographically.

Task 2:
- sort integers by number of '1' bits in their binary representation.
  example: {3, 7, 8} -> {8, 3, 7}, because 8 is 0b1000, 3 is 0x11, 7 id 0x111.

plus:
- add more test cases.
- try to use a function comparator and a lambda function.
*/
#include <algorithm>
#include <string>
#include <vector>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(Sort, ByLength) {
  std::vector<std::string> arr = {"a", "eleven", "seven__", "one", "eight___", "three", "four"};
  std::sort(arr.begin(), arr.end() /*, comparator*/);  // <- use std::sort, but with a custom comparator
  EXPECT_THAT(arr, ElementsAre("a", "one", "four", "three", "eleven", "seven__", "eight___"));

  arr = {"3333333", "55555", "777", "9", "88", "6666", "444444"};
  std::sort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre("9", "88", "777", "6666", "55555", "444444", "3333333"));
}

TEST(Sort, ByNumberOfBits) {
  std::vector<int> arr = {3, 7, 8};
  std::sort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(8, 3, 7));

  arr = {3, 16, 7, 15};
  std::sort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(16, 3, 7, 15));
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
