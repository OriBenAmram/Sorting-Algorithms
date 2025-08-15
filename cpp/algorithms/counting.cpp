#include "counting.hpp"
#include <algorithm>
#include <vector>

/*
Counting Sort (stable)
Steps:
1) Handle trivial input.
2) Find min and max to compute range.
3) Allocate count array, initialized to zero.
4) Count each element’s frequency (offset by min).
5) Prefix sums over count → cumulative counts.
6) Stable placement into output array (scan input from right to left).
7) Copy back into arr.
*/
void counting_sort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    int mn = *std::min_element(arr.begin(), arr.end());
    int mx = *std::max_element(arr.begin(), arr.end());
    size_t range = static_cast<size_t>(mx - mn + 1);

    std::vector<int> count(range, 0);
    for (int x : arr) count[x - mn]++;

    for (size_t i = 1; i < range; i++) count[i] += count[i - 1];

    std::vector<int> out(arr.size());
    for (size_t i = arr.size(); i-- > 0;) {
        int key = arr[i] - mn;
        count[key]--;
        out[count[key]] = arr[i];
    }

    arr.swap(out);
}
