#include "util.hpp"
#include <iostream>

void print_array(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void swap_int(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
