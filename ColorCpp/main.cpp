//
//  main.cpp
//  ColorCpp
//
//  Created by Robert Wallis on 11/19/19.
//  Copyright © 2019 Robert Wallis. All rights reserved.
//

#include <iostream>
#include <span>


void span() {
    char text[] = "Woah Spans work!";
    std::span<char> sp(text);
    for (auto const &c : sp) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    span();
    return 0;
}
