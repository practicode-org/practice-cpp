/*
Task:
- write series of template type traits that answer a question about a given type by providing a constant member value:
  - is_same - gives true for two types only if they are the same.
  - is_integral - gives true for integral types: char, short, int, long, long and unsigned variants, but false for others (including floats and doubles).
  - is_pointer - gives true for a pointer type (int *, const std::vector<int> *, etc).
  - is_const - gives true for const-qualified types (such as const int, const TestStruct, etc).
- pass all tests.

plus: also support volatile types
*/
#include <gtest/gtest.h>

// Is integral?
template <typename T>
struct is_integral {
  static const bool value = false;
};


// Is same?
template <typename A, typename B>
struct is_same {
  static const bool value = false;
};


// Is pointer?
template <typename T>
struct is_pointer {
  static const bool value = false;
};


// Is const?
template <typename T>
struct is_const {
  static const bool value = false;
};


// Auxilliary types
enum TestEnum {
};

struct TestStruct {
  int a;
};

struct AnotherStruct {
  int a;
};

// Helper variable templates
template <typename T>
constexpr bool is_integral_v = is_integral<T>::value;

template <typename A, typename B>
constexpr bool is_same_v = is_same<A, B>::value;

template <typename T>
constexpr bool is_pointer_v = is_pointer<T>::value;

template <typename T>
constexpr bool is_const_v = is_const<T>::value;


TEST(is_same, all) {
  EXPECT_TRUE((is_same_v<int, int>)); // Note: extra parenthesis needed to macro-expansion work properly. Otherwise preprocessor considers the comma not for the template, but for the macro parameters.
  EXPECT_TRUE((is_same_v<float, float>));
  EXPECT_TRUE((is_same_v<TestStruct, TestStruct>));
  EXPECT_TRUE((is_same_v<const unsigned long long, const unsigned long long>));
  EXPECT_TRUE((is_same_v<int *, int *>));
  EXPECT_TRUE((is_same_v<const int *, const int *>));
  EXPECT_TRUE((is_same_v<int &, int &>));
  EXPECT_TRUE((is_same_v<int * const, int * const>));
  EXPECT_TRUE((is_same_v<int const *, const int *>));

  EXPECT_FALSE((is_same_v<int, float>));
  EXPECT_FALSE((is_same_v<int, unsigned>));
  EXPECT_FALSE((is_same_v<float, double>));
  EXPECT_FALSE((is_same_v<long double, double>));
  EXPECT_FALSE((is_same_v<TestStruct, AnotherStruct>));
  EXPECT_FALSE((is_same_v<float *, double *>));
  EXPECT_FALSE((is_same_v<const int, int>));
  EXPECT_FALSE((is_same_v<const int *, int * const>));
}

TEST(is_integral, all) {
  EXPECT_TRUE(is_integral_v<int>);
  EXPECT_TRUE(is_integral_v<volatile int>);
  EXPECT_TRUE(is_integral_v<long>);
  EXPECT_TRUE(is_integral_v<long long>);
  EXPECT_TRUE(is_integral_v<char>);
  EXPECT_TRUE(is_integral_v<unsigned>);
  EXPECT_TRUE(is_integral_v<unsigned char>);
  EXPECT_TRUE(is_integral_v<unsigned long>);
  EXPECT_TRUE(is_integral_v<unsigned long long>);
  EXPECT_TRUE(is_integral_v<short>);
  EXPECT_TRUE(is_integral_v<unsigned short>);
  EXPECT_TRUE(is_integral_v<decltype(1)>);
  EXPECT_TRUE(is_integral_v<decltype(TestStruct::a)>);
  EXPECT_TRUE(is_integral_v<const int>);
  EXPECT_TRUE(is_integral_v<const unsigned long long>);

  EXPECT_FALSE(is_integral_v<int *>);
  EXPECT_FALSE(is_integral_v<int &>);
  EXPECT_FALSE(is_integral_v<float>);
  EXPECT_FALSE(is_integral_v<double>);
  EXPECT_FALSE(is_integral_v<long double>);
  EXPECT_FALSE(is_integral_v<TestStruct>);
  EXPECT_FALSE(is_integral_v<TestEnum>);
};

TEST(is_pointer, all) {
  EXPECT_TRUE(is_pointer_v<int *>);
  EXPECT_TRUE(is_pointer_v<int **>);
  EXPECT_TRUE(is_pointer_v<int ***>);
  EXPECT_TRUE(is_pointer_v<const int *>);
  EXPECT_TRUE(is_pointer_v<int * const>);
  EXPECT_TRUE(is_pointer_v<const unsigned long long * const>);

  EXPECT_FALSE(is_pointer_v<size_t>);
  EXPECT_FALSE(is_pointer_v<int *&>); // it's a reference in the first place
  EXPECT_FALSE(is_pointer_v<intptr_t>);
}

TEST(is_const, all) {
  EXPECT_TRUE(is_const_v<const int>);
  EXPECT_TRUE(is_const_v<const float>);
  EXPECT_TRUE(is_const_v<const double>);
  EXPECT_TRUE(is_const_v<const long double>);
  EXPECT_TRUE(is_const_v<const unsigned long long>);
  EXPECT_TRUE(is_const_v<int * const>); // the pointer itself is const, but not the value
  EXPECT_TRUE(is_const_v<const TestStruct>);
  EXPECT_TRUE(is_const_v<const TestEnum>);

  EXPECT_FALSE(is_const_v<TestStruct>);
  EXPECT_FALSE(is_const_v<float>);
  EXPECT_FALSE(is_const_v<int &>);
  EXPECT_FALSE(is_const_v<const int *>); // the int is const, not the pointer
  EXPECT_FALSE(is_const_v<const int &>); // the int is const, the reference can't be const
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
