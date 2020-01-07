//
// Created by Robert Wallis on 1/6/20.
//

#include <algorithm>
#include "gtest/gtest.h"

std::string doubleChar(std::string str) {
  std::string acc;
  std::for_each(
      str.begin(), str.end(),
      [&acc](int c) {
        acc.push_back(c);
        acc.push_back(c);
      }
  );
  return acc;
}

TEST(Edabit, DoubleLetter) {
  EXPECT_EQ("SSttrriinngg", doubleChar("String"));
  EXPECT_EQ("HHeelllloo  WWoorrlldd!!", doubleChar("Hello World!"));
  EXPECT_EQ("11223344!!__  ", doubleChar("1234!_ "));
}
