//
// Created by Robert Wallis on 1/5/20.
//

#include <algorithm>
#include "gtest/gtest.h"

char nextLetter(char c) {
  if (c == 'z') return 'a';
  if (c == 'Z') return 'A';
  return (char)(c + 1);
}

std::string mover(std::string word) {
  std::string moved;
  auto result = std::transform(
      word.begin(),
      word.end(),
      std::back_inserter(moved),
      nextLetter
  );
  return moved;
}

TEST(Edabit, TransformLetter) {
  EXPECT_EQ("bcde", mover("abcd"));
  EXPECT_EQ("ifmmp", mover("hello"));
  EXPECT_EQ("czf", mover("bye"));
  EXPECT_EQ("xfmdpnf", mover("welcome"));
  EXPECT_EQ("spubufa", mover("rotatez"));
}