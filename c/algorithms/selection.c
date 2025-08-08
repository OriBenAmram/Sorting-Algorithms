#include "selection.h"
#include "../util.h"  

void selection_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;

    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap_int(&arr[i], &arr[min_index]);
        }
    }
}
