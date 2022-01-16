/*
Task:
1) Partition the array of companies by 'dividends' criteria. Companies with dividends should precede companies that do
not pay dividends. Example: {SolidOptions     created Nov 1999, dividends: +, rating: Sell,         cap $5042001}
{TotalPlay        created Jun 1980, dividends: -, rating: Underperform, cap $961052}
{TechnoVision     created May 2018, dividends: -, rating: Outperform  , cap $6535232
{AutoScale        created Dec 1970, dividends: +, rating: Underperform, cap $11066993}

Partitioned:
{SolidOptions     created Nov 1999, dividends: +, rating: Sell,         cap $5042001}
{AutoScale        created Dec 1970, dividends: +, rating: Underperform, cap $11066993}
{TotalPlay        created Jun 1980, dividends: -, rating: Underperform, cap $961052}
{TechnoVision     created May 2018, dividends: -, rating: Outperform  , cap $6535232}

Try use approach with std::sort and then try more efficient std::partition. Compare number of move operations.

Self-check:
- std::partition used.
- tests don't fail (output is empty).

Plus: implement your own algorithm (without using STL).


2) Perform a partial sort (by descending capitalization): rearrange items such that first N of the result array contains
the largest companies (sorted) by capitalization. The order of the remaining elements is unspecified. Example with
numbers: Initial array: {8 6 2 5 7 2 3 9 1} Partially sorted (descending order) with N = 4: {9 8 7 6 2 2 3 5 1}. Note
that the resulting array is a permutation of the initial array.

Self-check:
- std::partial_sort used.
- tests don't fail (output is empty).

Plus: study and try partial sort **copy** algorithm.
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "internal/task_4.h"

/*
enum class Rating {
  Sell,
  Underperform,
  Hold,
  Outperform,
  Buy
};

struct Company {
  std::string name;
  time_point creation_date;
  bool dividends;
  Rating rating;
  uint64_t capitalization;
};*/

std::vector<Company> partitionByDividends(const std::vector<Company>& companies) {
  std::vector<Company> result;
  result = companies;

  // ...

  return result;
}

std::vector<Company> partialSortByCapitalization(const std::vector<Company>& companies,
                                                 int N) {  // don't change the function signature
  std::vector<Company> result;

  // ...

  return result;
}

int main() {
  {
    // Task 1
    auto companies = generateRandomCompanies(8);
    auto result = partitionByDividends(companies);

    // result correctess checks
    EXPECT_FALSE(result.empty());
    if (result.empty()) {
      auto iter = std::find_if(result.begin(), result.end(), [](const auto& c) { return !c.dividends; });
      EXPECT_TRUE(std::all_of(iter, result.end(), [](const auto& c) { return !c.dividends; }));
      EXPECT_TRUE(std::is_permutation(result.begin(), result.end(), companies.begin()));
    }
  }

  {
    // Task 2
    auto companies = generateRandomCompanies(14);
    int N = 3;  // we're only interested in top-3 companies
    auto result = partialSortByCapitalization(companies, N);

    // result correctess checks
    EXPECT_FALSE(result.empty());
    if (!result.empty()) {
      EXPECT_TRUE(std::is_sorted(result.begin(), result.begin() + N,
                                 [](const auto& a, const auto& b) { return b.capitalization < a.capitalization; }));
      EXPECT_TRUE(std::is_permutation(result.begin(), result.end(), companies.begin()));
    }
  }
  return 0;
}
