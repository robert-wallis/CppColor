//
//  LineInFile.hpp
//  ColorCpp
//
//  Created by Robert Wallis on 11/20/19.
//  Copyright © 2019 Robert Wallis. All rights reserved.
//

#ifndef LineInFile_h
#define LineInFile_h

#include <string>
#include <utility>

class LineInFunction {
  std::string function_name;
  int bracket_level;
  bool in_this_function;

 public:
  explicit LineInFunction(std::string function_name)
      : function_name(std::move(function_name)),
        bracket_level(0),
        in_this_function(false) {}

  bool operator()(const std::string &line) {
    if (!in_this_function) {
      if (line.find(function_name) != std::string::npos) {
        in_this_function = true;
      }
    }
    if (in_this_function) {
      bracket_level += bracket_count(line);
      if (bracket_level == 0) {
        in_this_function = false;
        return true;  // last time it's in the function
      }
    }
    return in_this_function;
  }

  int static bracket_count(const std::string &line) {
    int count = 0;
    for (const auto &c : line) {
      if (c == '{') {
        count++;
      } else if (c == '}') {
        count--;
      }
    }
    return count;
  }
};

#endif /* LineInFile_h */
