#include "bubble.hpp"
#include "../util.hpp"

void bubble_sort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    for (size_t i = 0; i + 1 < arr.size(); i++) {
        bool swapped = false;
        for (size_t j = 0; j + 1 < arr.size() - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
