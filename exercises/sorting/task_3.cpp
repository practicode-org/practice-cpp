/*
Task:
1) print elements of different containers in ascending order. You may change them by calling `sort` if needed.

plus: change to descending order
*/
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include "gtest/gtest.h"

TEST(AscendingOrder, Vector) {
  // Note: this task is already done
  std::vector<int> arr = {6, 5, 4, 1, 3, 2};

  std::sort(std::begin(arr), std::end(arr));

  testing::internal::CaptureStdout();

  for (auto item : arr) {
    std::cout << item << " ";
  }

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 "); // Note: the last whitespace is just for convenience
}

TEST(AscendingOrder, CArray) {
  int arr[] = {6, 5, 4, 1, 3, 2};

  // ...

  testing::internal::CaptureStdout();

  // TODO: printing

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 ");
}

TEST(AscendingOrder, Deque) {
  std::deque<int> arr = {6, 5, 4, 1, 3, 2};

  testing::internal::CaptureStdout();

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 ");
}

TEST(AscendingOrder, List) {
  std::list<int> arr = {6, 5, 4, 1, 3, 2};

  testing::internal::CaptureStdout();

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 ");
}

TEST(AscendingOrder, Map) {
  std::map<int, int> arr = {{6, 600}, {5, 500}, {4, 400}, {1, 100}, {3, 300}, {2, 200}};

  testing::internal::CaptureStdout();

  // print only keys

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 ");
}

TEST(AscendingOrder, UnorderedMap) {
  std::unordered_map<int, int> arr = {{6, 600}, {5, 500}, {4, 400}, {1, 100}, {3, 300}, {2, 200}};

  testing::internal::CaptureStdout();

  // print only keys

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 ");
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
