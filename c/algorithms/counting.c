#include "counting.h"
#include <stdlib.h>

/*
Counting Sort (stable)
Steps:
1) Handle trivial input (length < 2).
2) Find min and max to compute the range.
3) Allocate count array of size R = max - min + 1, initialized to zero.
4) Count each element's frequency (offset by min so negatives work).
5) Prefix sums over count array → cumulative counts (final positions).
6) Allocate output array and fill it stably (scan input from right to left).
7) Copy output back into arr and free temp arrays.
*/
void counting_sort(int* arr, size_t length) {
    if (length < 2) return;

    int min = arr[0], max = arr[0];
    for (size_t i = 1; i < length; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    size_t range = (size_t)(max - min + 1);
    int* count = (int*)calloc(range, sizeof(int));
    if (!count) return;

    for (size_t i = 0; i < length; i++) {
        count[arr[i] - min]++;
    }

    for (size_t i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    int* output = (int*)malloc(length * sizeof(int));
    if (!output) { free(count); return; }

    for (size_t i = length; i-- > 0;) {
        int key = arr[i] - min;
        count[key]--;
        output[count[key]] = arr[i];
    }

    for (size_t i = 0; i < length; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}
