//
//  main.cpp
//  ColorCpp
//
//  Created by Robert Wallis on 11/19/19.
//  Copyright © 2019 Robert Wallis. All rights reserved.
//

#include <iostream>

#include "p8.hpp"
#include "spans.hpp"

int main(int argc, const char *argv[]) {
  std::cout << "=== span ===" << std::endl;
  span();
  compile_time_span();

  std::cout << "=== p8 ===" << std::endl;
  p8_raii_file();

  return 0;
}
