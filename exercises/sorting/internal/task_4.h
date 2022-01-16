#pragma once
#include <algorithm>  // find
#include <cctype>     // tolower
#include <chrono>
#include <cmath>    // fabs
#include <ctime>    // strftime
#include <iomanip>  // setw
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace {
std::random_device rnd;
std::default_random_engine rne(rnd());
}  // namespace

using time_point = std::chrono::system_clock::time_point;

enum class Rating { Sell, Underperform, Hold, Outperform, Buy };

struct Company {
  std::string name;
  time_point creation_date;
  bool dividends;
  Rating rating;
  uint64_t capitalization;
};

bool operator==(const Company& a, const Company& b) {
  return a.name == b.name && a.creation_date == b.creation_date && a.dividends == b.dividends && a.rating == b.rating &&
         a.capitalization == b.capitalization;
}

std::ostream& operator<<(std::ostream& os, time_point t) {
  std::time_t tp = std::chrono::system_clock::to_time_t(t);
  char buf[200] = {};
  strftime(buf, sizeof(buf), "%b %Y", std::localtime(&tp));
  os << buf;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Company& c) {
  static const char* rating_to_str[] = {
      "Sell", "Underperform", "Hold", "Outperform", "Buy",
  };
  os << "{" << std::setw(24) << std::left << c.name << " created " << c.creation_date << ", ";
  os << "dividends: " << (c.dividends ? '+' : '-') << ", ";
  os << "rating: " << std::setw(12) << std::left << rating_to_str[(int)c.rating] << ", ";
  os << "cap $" << c.capitalization << "}";
  return os;
}

std::string generateName() {
  static const char* prefix[] = {
      "Great",   "Titan",  "Terra",   "Far",     "White",  "Black",  "The",     "Big",         "New",    "Total",
      "Global",  "Smart",  "My",      "One",     "First",  "Uni",    "Mono",    "Any",         "Auto",   "Retro",
      "Nano",    "Micro",  "Mega",    "Monster", "Tele",   "Crypto", "Virtual", "Meta",        "Beyond", "Astro",
      "Sonic",   "Air",    "Edu",     "Invest",  "Legal",  "Game",   "Group",   "Dark",        "Bright", "Live",
      "Quantum", "Stone",  "Final",   "Leet",    "Elite",  "Hacker", "Green",   "Veg",         "Vip",    "Bio",
      "Alpha",   "Beam",   "Golden",  "Coin",    "Energy", "Front",  "General", "Git",         "Inno",   "Iron",
      "Lumen",   "Lucid",  "Auto",    "Man",     "Mesa",   "Navi",   "Nova",    "North",       "Omni",   "Proto",
      "Open",    "Red",    "Ring",    "Rock",    "Smart",  "South",  "Tera",    "Octa",        "Trans",  "West",
      "Central", "Zen",    "Next",    "Anti",    "Human",  "Your",   "Right",   "Z",           "Atomic", "Zero",
      "Top",     "7",      "Intelli", "Spin",    "Techno", "Securi", "Click",   "Electric",    "Blue",   "Arctic",
      "Real",    "Prima",  "Every",   "Digital", "Tiny",   "Local",  "Neo",     "Vibrant",     "Double", "Excel",
      "Nerd",    "Deep",   "Alien",   "Hidden",  "Mobile", "Byte",   "City",    "Jungle",      "Sand",   "Rapid",
      "Third",   "Square", "Classic", "Better",  "Solid",  "Pocket", "Arc",     "Fisherman's", "Only",   "Rising",
      "Daily",   "United", "Fast"};
  static const char* name[] = {"Arrival",    "Ocean",      "Body",       "Brain",   "Splash",    "Science",
                               "Joy",        "Jump",       "Drive",      "Motors",  "Connect",   "Push",
                               "Mash",       "Tube",       "Wire",       "Media",   "Sync",      "Storm",
                               "Boom",       "Spark",      "Wave",       "Tech",    "Motion",    "Sun",
                               "Moon",       "Land",       "Orange",     "Star",    "Byte",      "Bit",
                               "Mia",        "Signal",     "Scope",      "Soft",    "Book",      "Game",
                               "Therapy",    "Meat",       "Code",       "Fly",     "Toy",       "Sight",
                               "Nine",       "Flow",       "Leap",       "Flex",    "Factor",    "Craft",
                               "Day",        "Art",        "Dog",        "Strike",  "Research",  "Energy",
                               "Industries", "Pharm",      "Python",     "Align",   "Care",      "Financial",
                               "Gen",        "Cast",       "Metal",      "Telecom", "Materials", "Pharmaceuticals",
                               "Data",       "Pay",        "Health",     "Sys",     "Point",     "Path",
                               "Bank",       "Galactic",   "Investment", "Trust",   "Water",     "Thing",
                               "Stock",      "Dream",      "Nature",     "Box",     "Tap",       "Talent",
                               "Grow",       "Travel",     "Fire",       "Sports",  "Ventures",  "Fluence",
                               "Carrot",     "Web",        "Coffee",     "Time",    "Step",      "Home",
                               "Wine",       "Barber",     "Legend",     "Idea",    "Run",       "Volume",
                               "Growth",     "Philosophy", "Market",     "Cup",     "Baby",      "Mile",
                               "Fork",       "Hat",        "Hub",        "Gate",    "Tide",      "Era",
                               "Dance",      "Jobs",       "Cow",        "Event",   "Pod",       "Start",
                               "App",        "Reality",    "Show",       "Design",  "Light",     "Seed",
                               "Mind",       "Touch",      "Tomorrow",   "Today",   "Plant",     "Ray",
                               "Soil",       "Work",       "Dash",       "Rockets", "Fuel",      "Sign",
                               "Computing",  "Way",        "Road",       "Future",  "Scale",     "Heritage",
                               "Robotics",   "Robots",     "Mail",       "Vision",  "Proton",    "Quark",
                               "Electron",   "Atom",       "Cross",      "Fog",     "Reach",     "Fitness",
                               "Rain",       "Drop",       "Clover",     "Horizon", "Rubber",    "Space",
                               "Station",    "Traders",    "Options",    "Brother", "Jets",      "Axis",
                               "Innovation", "Scape",      "Realm",      "Rover",   "Post",      "Depot",
                               "Alliance",   "Play"};
  static const char* postfix[] = {"Tech", "Lab",   "Team",    "Soft",    "Shop",    "Platform", "Inc",
                                  "Corp", "Group", "Holding", "Systems", "Academy", "Cafe",     "Agency"};

  std::string result;

  std::uniform_int_distribution<int> prefix_dist(0, std::size(prefix) - 1);
  std::uniform_int_distribution<int> name_dist(0, std::size(name) - 1);

  result += prefix[prefix_dist(rne)];
  result += name[name_dist(rne)];

  if (std::uniform_int_distribution<int>(0, 5)(rne) == 0) {
    std::uniform_int_distribution<int> postfix_dist(0, std::size(postfix) - 1);
    result += ' ';
    result += postfix[postfix_dist(rne)];
  }
  return result;
}

std::chrono::system_clock::time_point randomDate() {
  std::uniform_int_distribution<int> seconds_dist(1, 3600 * 24);  // adjust seconds within the day
  std::uniform_int_distribution<int> days_dist(1, 365);           // adjust number of days back in time
  std::uniform_int_distribution<int> years_dist(1, 60);           // adjust years
  return std::chrono::system_clock::now() - std::chrono::seconds(seconds_dist(rne)) -
         std::chrono::hours(days_dist(rne)) * 24 - std::chrono::hours(years_dist(rne)) * 24 * 365;
}

std::vector<Company> generateRandomCompanies(int N) {
  std::vector<Company> result;

  std::normal_distribution<double> capitalization_dist(0, 10'000'000);
  std::uniform_int_distribution dividends_dist(0, 1);
  std::uniform_int_distribution rating_dist(0, (int)Rating::Buy);

  for (int i = 0; i < N; i++) {
    result.push_back(Company{generateName(), randomDate(), dividends_dist(rne) == 1, (Rating)rating_dist(rne),
                             (uint64_t)std::fabs(capitalization_dist(rne))});
  }

  return result;
}

// for stable sort
void checkOrderPreserved(const std::vector<Company>& v1, const std::vector<Company>& v2) {
  for (auto i = 1u; i < v2.size(); i++) {
    const auto& a = v2[i - 1];
    const auto& b = v2[i];

    if (!(a.rating < b.rating) && !(b.rating < a.rating)) {
      // two adjacent companies are equivalent
      // check thier order in the first array
      if (std::find(v1.begin(), v1.end(), a) >
          std::find(v1.begin(), v1.end(),
                    b)) {  // yes, it's O(N^2), but it doesn't matter much in an educational application
        std::cerr << "\nError: Order was not preserved for equivalent items \"" << a.name << "\" and \"" << b.name
                  << "\" (compared by rating)." << std::endl;
        return;
      }
    }
  }
}
