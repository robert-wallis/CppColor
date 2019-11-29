//
//  spans.cpp
//  ColorCpp
//
//  Created by Robert Wallis on 11/19/19.
//  Copyright © 2019 Robert Wallis. All rights reserved.
//

#include "spans.hpp"
#include <iostream>

void span() {
  int numbers[] = {4, 8, 15, 16, 23, 42};
  std::span<int> sp(numbers);
  int count = 0;
  for (auto const &c : sp) {
    std::cout << c << ", ";
    count++;
  }
  std::cout << std::endl;
  std::cout << count << " numbers printed" << std::endl;
}

int sum(std::span<int> list) {
  int total = 0;
  for (const auto &i : list) {
    total += i;
  }
  return total;
}

void compile_time_span() {
  int list[] = {1, 2, 3};

  int total = sum({list, 4});  // should compile time error, 4 > 3 :(
  std::cout << total << std::endl;

  int total2 = sum(list);
  std::cout << total2 << std::endl;
}
