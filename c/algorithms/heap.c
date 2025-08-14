#include <stddef.h>

static void sift_down(int* a, size_t start, size_t end) {
    size_t root = start;

    while (1) {
        size_t child = 2 * root + 1;           // left child
        if (child > end) break;                 // no children

        if (child + 1 <= end && a[child] < a[child + 1]) {
            child += 1;                         // choose larger child
        }

        if (a[root] < a[child]) {
            int tmp = a[root];
            a[root] = a[child];
            a[child] = tmp;
            root = child;                       // continue sifting
        } else {
            break;                              // heap property satisfied
        }
    }
}

void heap_sort(int* numbers, size_t length) {
    if (length < 2) return;

    // Build max-heap in-place (bottom-up)
    for (size_t i = (length - 2) / 2 + 1; i-- > 0; ) {
        sift_down(numbers, i, length - 1);
    }

    // Repeatedly move max to the end, shrink heap, and fix root
    for (size_t end = length - 1; end > 0; --end) {
        int tmp = numbers[0];
        numbers[0] = numbers[end];
        numbers[end] = tmp;
        sift_down(numbers, 0, end - 1);
    }
}
