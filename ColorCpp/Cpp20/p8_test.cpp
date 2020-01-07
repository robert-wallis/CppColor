//
//  p8.cpp
//  ColorCpp
//
//  Created by Robert Wallis on 11/19/19.
//  Copyright © 2019 Robert Wallis. All rights reserved.
//


#include <fstream>
#include <iostream>
#include "gtest/gtest.h"

#include "LineInFunction.hpp"

TEST(P8, RaiiFile) {
  std::ifstream file{__FILE__};
  std::string line;
  auto in_func = LineInFunction(__FUNCTION__);
  while (file.good()) {
    std::getline(file, line);
    if (in_func(line)) {
      std::cout << line << std::endl;
    }
  }
}
