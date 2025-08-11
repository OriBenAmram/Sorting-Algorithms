#include "merge.h"
#include <stdlib.h>
#include <string.h>

static void merge(int *a, size_t left, size_t mid, size_t right, int *tmp) {
    size_t i = left, j = mid, k = left;

    while (i < mid && j < right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }
    while (i < mid)  tmp[k++] = a[i++];
    while (j < right) tmp[k++] = a[j++];

    memcpy(a + left, tmp + left, (right - left) * sizeof(int));
}

void merge_sort(int *a, size_t n) {
    if (n <= 1 || !a) return;

    int *tmp = malloc(n * sizeof(int));
    if (!tmp) return;

    // Bottom-up iterative merge sort
    for (size_t width = 1; width < n; width <<= 1) {
        for (size_t left = 0; left < n; left += (width << 1)) {
            size_t mid   = left + width;
            size_t right = left + (width << 1);
            if (mid > n) mid = n;
            if (right > n) right = n;
            if (mid < right) {
                merge(a, left, mid, right, tmp);
            }
        }
    }

    free(tmp);
}
