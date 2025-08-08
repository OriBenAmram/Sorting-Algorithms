#include "insertion.h"
#include "../util.h" 

void insertion_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;

    for (size_t i = 1; i < n; i++) {
        size_t j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap_int(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}
