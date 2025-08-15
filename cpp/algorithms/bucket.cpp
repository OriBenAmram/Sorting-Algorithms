#include "bucket.hpp"
#include <vector>
#include <algorithm>
#include <cmath>

/*
Bucket Sort (for floats in roughly uniform distribution)
1) Find min/max.
2) Create k buckets (k = arr.size()).
3) Map each element to a bucket by normalized position.
4) Sort each bucket individually.
5) Concatenate buckets back into arr.
*/
static void insertion_sort(std::vector<double>& b) {
    for (size_t i = 1; i < b.size(); i++) {
        double key = b[i];
        size_t j = i;
        while (j > 0 && b[j - 1] > key) {
            b[j] = b[j - 1];
            j--;
        }
        b[j] = key;
    }
}

void bucket_sort(std::vector<double>& arr) {
    if (arr.size() < 2) return;

    double mn = *std::min_element(arr.begin(), arr.end());
    double mx = *std::max_element(arr.begin(), arr.end());
    if (mn == mx) return;

    size_t k = arr.size();
    double range = mx - mn;
    std::vector<std::vector<double>> buckets(k);

    for (double x : arr) {
        size_t idx = static_cast<size_t>((x - mn) / range * (k - 1));
        buckets[idx].push_back(x);
    }

    size_t pos = 0;
    for (auto& b : buckets) {
        insertion_sort(b);
        for (double x : b) arr[pos++] = x;
    }
}
