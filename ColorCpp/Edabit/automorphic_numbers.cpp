//
// Created by Robert Wallis on 1/6/20.
//

#include "gtest/gtest.h"

bool isAutomorphic(int n) {
  int64_t nn = (int64_t)n * (int64_t)n;
  for (auto i = 0; n > 0; i++, n = n / 10, nn = nn / 10) {
    if (n % 10 != nn % 10) {
      return false;
    }
  }
  return true;
}

TEST(Edabit, AutomorphicNumbers) {
  EXPECT_EQ(true, isAutomorphic(5));
  EXPECT_EQ(false, isAutomorphic(8));
  EXPECT_EQ(true, isAutomorphic(76));
  EXPECT_EQ(true, isAutomorphic(0));
  EXPECT_EQ(true, isAutomorphic(7109376));
}
