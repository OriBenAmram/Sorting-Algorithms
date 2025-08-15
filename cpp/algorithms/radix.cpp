#include "radix.hpp"
#include <vector>
#include <algorithm>
#include <cstdlib>

static void lsd_nonneg(std::vector<int>& arr) {
    if (arr.size() < 2) return;
    const int BASE = 256;
    int maxv = *std::max_element(arr.begin(), arr.end());
    int passes = (maxv == 0) ? 1 : ((32 - __builtin_clz(maxv) + 7) / 8);

    std::vector<int> output(arr.size());
    for (int p = 0; p < passes; p++) {
        int count[BASE] = {0};
        int shift = 8 * p;

        for (int x : arr) count[(x >> shift) & 0xFF]++;

        for (int i = 1; i < BASE; i++) count[i] += count[i - 1];

        for (size_t i = arr.size(); i-- > 0;) {
            int d = (arr[i] >> shift) & 0xFF;
            count[d]--;
            output[count[d]] = arr[i];
        }
        arr.swap(output);
    }
}

void radix_sort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    std::vector<int> neg, pos;
    for (int x : arr) {
        if (x < 0) neg.push_back(-x);
        else pos.push_back(x);
    }

    lsd_nonneg(pos);
    lsd_nonneg(neg);

    size_t idx = 0;
    for (size_t i = neg.size(); i-- > 0;) arr[idx++] = -neg[i];
    for (int x : pos) arr[idx++] = x;
}
