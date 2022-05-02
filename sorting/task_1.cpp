/*
Task:
- write a function that returns true if the given sequence is sorted.
- pass all tests.

plus: add your own tests.
plus: you have a STL-based implementation and a manual variant.
plus: support for a reverse-sorted sequences too.
plus: write a template based variant that may work with vector of different types
plus: write a function that accepts two input iterators (begin, end)
*/
#include <iostream>
#include <vector>
#include <limits>
#include "gtest/gtest.h"

bool is_sorted(const std::vector<int> &arr) {
  // TODO: implement
  return false;
}

TEST(is_sorted, all) {
  EXPECT_TRUE(is_sorted({1, 2, 3, 4, 5}));
  EXPECT_TRUE(is_sorted({1}));
  EXPECT_TRUE(is_sorted({2, 2, 2}));
  EXPECT_TRUE(is_sorted({-5, -4, -3, -2, -1}));
  EXPECT_FALSE(is_sorted({5, 4, 3, 2, 1}));
  EXPECT_TRUE(is_sorted({-5, -5, 5, 5}));
  EXPECT_TRUE(is_sorted({-5, -4}));
  EXPECT_TRUE(is_sorted({std::numeric_limits<int>::min(), 1, 1, 2, 10, 15, std::numeric_limits<int>::max()}));
  EXPECT_FALSE(is_sorted({1, 2, 1, 3, 4, 5}));
  EXPECT_FALSE(is_sorted({1, 2, 3, 2}));
  EXPECT_FALSE(is_sorted({3, 2, 3, 4}));
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
