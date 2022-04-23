/*
Task:
1) write `find` function that gets a sorted vector and a number and returns index of the number (or -1 if not found).
  Use `std::lower_bound` (O(log N) runtime complexity).

2) write `insert_into_sorted` function that inserts a number to the vector and keeps it sorted.

plus: study difference between lower_bound and upper_bound, try them both.
plus: write your own implementations without using STL.
plus: add your own tests.
plus: write templated variants that may accept a vector of a custom type.
plus: will the functions work with std::deque? std::list? Try it out.
*/
#include <vector>
#include <algorithm>
#include <iterator>
#include "gtest/gtest.h"

size_t find(const std::vector<int>& arr, int num) {
  // ...
  return 0;
}

void insert_into_sorted(std::vector<int>& arr, int num) {
  // ...
}

TEST(find, all) {
  // Note: input array must be sorted
  EXPECT_EQ((find(std::vector{1}, 10)), -1);
  EXPECT_EQ((find(std::vector{1, 2, 3}, 4)), -1);
  EXPECT_EQ((find(std::vector{1, 2, 4}, 3)), -1);

  EXPECT_EQ((find(std::vector{10, 11, 12}, 10)), 0);
  EXPECT_EQ((find(std::vector{10, 11, 12}, 11)), 1);
  EXPECT_EQ((find(std::vector{10, 11, 12}, 12)), 2);
  EXPECT_EQ((find(std::vector{10, 11, 12, 20, 21, 22}, 12)), 2);
  EXPECT_EQ((find(std::vector{10, 11, 12, 20, 21, 22}, 20)), 3);
  EXPECT_EQ((find(std::vector{10, 11, 12, 20, 21, 22}, 22)), 5);
  EXPECT_EQ((find(std::vector{10, 11, 12, 20, 21, 22}, 15)), -1);
  EXPECT_EQ((find(std::vector{-10, -10, -10, -10, 0}, 0)), 4);
}

TEST(insert_into_sorted, all) {
  std::vector<int> v{};

  insert_into_sorted(v, 5);
  EXPECT_EQ(v, std::vector{5});

  insert_into_sorted(v, 5);
  EXPECT_EQ(v, (std::vector{5, 5}));

  insert_into_sorted(v, 0);
  EXPECT_EQ(v, (std::vector{0, 5, 5}));

  insert_into_sorted(v, 2);
  EXPECT_EQ(v, (std::vector{0, 2, 5, 5}));

  insert_into_sorted(v, 1);
  EXPECT_EQ(v, (std::vector{0, 1, 2, 5, 5}));

  insert_into_sorted(v, 4);
  EXPECT_EQ(v, (std::vector{0, 1, 2, 4, 5, 5}));

  insert_into_sorted(v, 0);
  EXPECT_EQ(v, (std::vector{0, 0, 1, 2, 4, 5, 5}));
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
