//
//  spans.cpp
//  ColorCpp
//
//  Created by Robert Wallis on 11/29/19.
//  Copyright © 2019 Robert Wallis. All rights reserved.
//

#include <span>
#include "gtest/gtest.h"

TEST(CppSpan, Basic) {
  int numbers[] = {4, 8, 15, 16, 23, 42};
  std::span<int> sp(numbers);
  int count = 0;
  int sum = 0;
  for (auto const &c : sp) {
    sum += c;
    count++;
  }
  EXPECT_EQ(6, count);
  EXPECT_EQ(108, sum);
}

int sum(std::span<int> list) {
  int total = 0;
  for (const auto &i : list) {
    total += i;
  }
  return total;
}

TEST(CppSpan, SumNormalSpan) {
  int list[] = {1, 2, 3};
  EXPECT_EQ(6, sum(list));
}

TEST(CppSpan, OverBoundsShouldWarnOrError) {
  int list[] = {1, 2, 3};
  int total = sum({list, 4});  // should compile time error, 4 > 3 :(
  EXPECT_NE(0, total);
}
