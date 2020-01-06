//
// Created by Robert Wallis on 1/5/20.
//

#include <vector>
#include <numeric>
#include "gtest/gtest.h"

int trGetAbsSum(std::vector<int> arr) {
//  return std::transform_reduce(arr.begin(), arr.end(), 0, std::plus<>(), [](int x) { return std::abs(x);});
  return std::transform_reduce(
      arr.begin(),
      arr.end(),
      0,
      std::plus<>(),
      static_cast<int (*)(int)>(&std::abs)
  );
}

int getAbsSum(std::vector<int> arr) {
  return std::accumulate(
      arr.begin(),
      arr.end(),
      0,
      [](int a, int b) { return a + std::abs(b); }
  );
}

TEST(Transform, TransformReducer) {
  EXPECT_EQ(1, trGetAbsSum(std::vector({-1})));
  EXPECT_EQ(30, trGetAbsSum(std::vector({2, 4, 6, 8, 10})));
  EXPECT_EQ(22, trGetAbsSum(std::vector({-3, -4, -10, -2, -3})));
  EXPECT_EQ(25, trGetAbsSum(std::vector({2, -1, 4, 8, 10})));
}

TEST(Transform, Accumulate) {
  EXPECT_EQ(1, getAbsSum(std::vector({-1})));
  EXPECT_EQ(30, getAbsSum(std::vector({2, 4, 6, 8, 10})));
  EXPECT_EQ(22, getAbsSum(std::vector({-3, -4, -10, -2, -3})));
  EXPECT_EQ(25, getAbsSum(std::vector({2, -1, 4, 8, 10})));
}
