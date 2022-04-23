/*
This program prints companies on a stock market.
Task:
- sort companies with three criterias: `dividends` first, then `rating`, then `capitalization`.
  This means that companies are compared by `dividends`, but if these fields are equal then the next field is used for comparison.

For example, these companies:
{DailyMarket              created Jan 1975, dividends, rating: Hold        , cap $15568997}
{SecuriWine Consulting    created May 1987, dividends, rating: Outperform  , cap $8729992}
{TeleBank Tech            created Aug 2003           , rating: Buy         , cap $17549087}
{FrontTravel              created Dec 1978, dividends, rating: Hold        , cap $631681}
{HiddenJets               created May 1980, dividends, rating: Outperform  , cap $12008927}

Would be sorted as such:
{HiddenJets               created May 1980, dividends, rating: Outperform  , cap $12008927}
{SecuriWine Consulting    created May 1987, dividends, rating: Outperform  , cap $8729992}
{DailyMarket              created Jan 1975, dividends, rating: Hold        , cap $15568997}
{FrontTravel              created Dec 1978, dividends, rating: Hold        , cap $631681}
{TeleBank Tech            created Aug 2003           , rating: Buy         , cap $17549087}

plus: check by using std::is_sorted
plus: sort in reverse direction
plus: add one more order criteria
plus: try `stable_sort` and examine its guarantees
*/
#include "internal/task_4.h"
#include <algorithm>
#include <iostream>
#include <vector>

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

int main() {
  std::vector<Company> companies = generateRandomCompanies(18);

  // ...

  for (const auto& c : companies) {
    std::cout << c << std::endl;
  }

  return 0;
}
