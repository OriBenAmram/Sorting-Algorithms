#include "merge.hpp"
#include <vector>
#include <cstddef>
#include <algorithm> // std::min

namespace {
    void merge_runs(std::vector<int>& a, std::size_t left,
                    std::size_t mid, std::size_t right,
                    std::vector<int>& tmp)
    {
        std::size_t i = left, j = mid, k = left;
        while (i < mid && j < right) {
            if (a[i] <= a[j]) tmp[k++] = a[i++];
            else              tmp[k++] = a[j++];
        }
        while (i < mid)  tmp[k++] = a[i++];
        while (j < right) tmp[k++] = a[j++];
        for (std::size_t t = left; t < right; ++t) a[t] = tmp[t];
    }
}

void merge_sort(std::vector<int>& a)
{
    const std::size_t n = a.size();
    if (n <= 1) return;

    std::vector<int> tmp(n);
    // width = size of runs to merge; double each pass
    for (std::size_t width = 1; width < n; width <<= 1) {
        for (std::size_t left = 0; left < n; left += (width << 1)) {
            std::size_t mid   = std::min(left + width, n);
            std::size_t right = std::min(left + (width << 1), n);
            if (mid < right) {
                merge_runs(a, left, mid, right, tmp);
            }
        }
    }
}
