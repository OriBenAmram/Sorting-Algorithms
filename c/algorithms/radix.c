#include "radix.h"
#include <stdlib.h>
#define BASE 256

/*
LSD Radix Sort (base 256)
1) Split negatives and non-negatives.
2) Sort each using stable byte-wise counting sort.
3) For negatives: sort their absolute values, then reverse and reapply sign.
4) Concatenate negatives and positives back into arr.
*/
static void lsd_nonneg(int* arr, size_t n) {
    if (n < 2) return;
    int* output = (int*)malloc(n * sizeof(int));
    if (!output) return;

    int maxv = arr[0];
    for (size_t i = 1; i < n; i++)
        if (arr[i] > maxv) maxv = arr[i];

    int passes = (maxv == 0) ? 1 : ((32 - __builtin_clz(maxv) + 7) / 8);

    for (int p = 0; p < passes; p++) {
        int count[BASE] = {0};
        int shift = 8 * p;

        for (size_t i = 0; i < n; i++)
            count[(arr[i] >> shift) & 0xFF]++;

        for (int i = 1; i < BASE; i++)
            count[i] += count[i - 1];

        for (size_t i = n; i-- > 0;) {
            int d = (arr[i] >> shift) & 0xFF;
            count[d]--;
            output[count[d]] = arr[i];
        }

        for (size_t i = 0; i < n; i++)
            arr[i] = output[i];
    }

    free(output);
}

void radix_sort(int* arr, size_t length) {
    if (length < 2) return;

    int* neg = (int*)malloc(length * sizeof(int));
    int* pos = (int*)malloc(length * sizeof(int));
    if (!neg || !pos) { free(neg); free(pos); return; }

    size_t nneg = 0, npos = 0;
    for (size_t i = 0; i < length; i++) {
        if (arr[i] < 0) neg[nneg++] = -arr[i];
        else pos[npos++] = arr[i];
    }

    lsd_nonneg(pos, npos);
    lsd_nonneg(neg, nneg);

    size_t idx = 0;
    for (size_t i = nneg; i-- > 0;) arr[idx++] = -neg[i];
    for (size_t i = 0; i < npos; i++) arr[idx++] = pos[i];

    free(neg);
    free(pos);
}
