#include "selection.hpp"
#include "../util.hpp"

void selection_sort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap_int(arr[i], arr[min_index]);
        }
    }
}
