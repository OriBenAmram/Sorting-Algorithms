#include "util.h"
#include <stdio.h>

void print_array(const int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
