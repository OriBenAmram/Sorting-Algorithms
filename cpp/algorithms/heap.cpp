#include "heap.hpp"

static void sift_down(std::vector<int>& a, size_t start, size_t end) {
    size_t root = start;

    while (true) {
        size_t child = 2 * root + 1;           // left child index
        if (child > end) break;                 // no children

        if (child + 1 <= end && a[child] < a[child + 1]) {
            child += 1;                         // pick right child if larger
        }

        if (a[root] < a[child]) {
            std::swap(a[root], a[child]);
            root = child;                       // continue down
        } else {
            break;                              // heap property holds
        }
    }
}

void heap_sort(std::vector<int>& numbers) {
    if (numbers.size() < 2) return;

    // Build max-heap
    for (size_t i = (numbers.size() - 2) / 2 + 1; i-- > 0; ) {
        sift_down(numbers, i, numbers.size() - 1);
    }

    // Extract elements from heap
    for (size_t end = numbers.size() - 1; end > 0; --end) {
        std::swap(numbers[0], numbers[end]);
        sift_down(numbers, 0, end - 1);
    }
}
