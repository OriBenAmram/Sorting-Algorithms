#include "bucket.h"
#include <stdlib.h>

/*
Bucket Sort (for floats in roughly uniform distribution)
1) Find min/max.
2) Create k buckets (k = length).
3) Map each element to a bucket by normalized position.
4) Sort each bucket (insertion sort here for small size).
5) Concatenate buckets back to arr.
*/
static void insertion_sort(double* arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        double key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void bucket_sort(double* arr, size_t length) {
    if (length < 2) return;

    double min = arr[0], max = arr[0];
    for (size_t i = 1; i < length; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    if (min == max) return;

    size_t k = length;
    double range = max - min;
    double** buckets = (double**)calloc(k, sizeof(double*));
    size_t* sizes = (size_t*)calloc(k, sizeof(size_t));

    if (!buckets || !sizes) { free(buckets); free(sizes); return; }

    // First pass: count bucket sizes
    for (size_t i = 0; i < length; i++) {
        size_t idx = (size_t)((arr[i] - min) / range * (k - 1));
        sizes[idx]++;
    }

    // Allocate buckets
    for (size_t i = 0; i < k; i++) {
        buckets[i] = (double*)malloc(sizes[i] * sizeof(double));
        sizes[i] = 0; // reset for insertion
    }

    // Fill buckets
    for (size_t i = 0; i < length; i++) {
        size_t idx = (size_t)((arr[i] - min) / range * (k - 1));
        buckets[idx][sizes[idx]++] = arr[i];
    }

    // Sort and merge
    size_t pos = 0;
    for (size_t i = 0; i < k; i++) {
        insertion_sort(buckets[i], sizes[i]);
        for (size_t j = 0; j < sizes[i]; j++) {
            arr[pos++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(sizes);
}
