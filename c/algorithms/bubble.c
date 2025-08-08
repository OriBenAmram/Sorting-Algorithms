#include "bubble.h"
#include "../util.h"  // for swap_int

void bubble_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;

    for (size_t i = 0; i + 1 < n; i++) {
        int swapped = 0;
        for (size_t j = 0; j + 1 < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // Optimization trick - if no swaps occur, the array is already sorted and we can stop early.
        if (!swapped) break;
    }
}
