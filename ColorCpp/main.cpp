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

int sum(std::span<int> list) {
    int total = 0;
    for (const auto &i : list) {
        total += i;
    }
    return total;
}

void compile_time_span() {
    int list[3] = { 1, 2, 3 };

    int total = sum({list, 4}); // should compile time error, 4 > 3 :(
    std::cout << total << std::endl;

    int total2 = sum(list);
    std::cout << total2 << std::endl;
}

int main(int argc, const char * argv[]) {
    span();
    compile_time_span();
    return 0;
}
