#include "insertion.hpp"
#include "../util.hpp"

void insertion_sort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    for (size_t i = 1; i < arr.size(); i++) {
        size_t j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap_int(arr[j], arr[j - 1]);
            j--;
        }
    }
}
