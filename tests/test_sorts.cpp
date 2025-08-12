#include <cassert>
#include <vector>
#include "../cpp/algorithms/bubble.hpp"
#include "../cpp/algorithms/selection.hpp"
#include "../cpp/algorithms/insertion.hpp"
#include "../cpp/algorithms/merge.hpp"
#include "../cpp/algorithms/quick.hpp"

using SortFn = void(*)(std::vector<int>&);

static void run_all(SortFn sort) {
    {
        std::vector<int> v{};
        sort(v);
        assert(v.empty());
    }
    {
        std::vector<int> v{1};
        sort(v);
        assert((v == std::vector<int>{1}));
    }
    {
        std::vector<int> v{3, 1, 2};
        sort(v);
        assert((v == std::vector<int>{1, 2, 3}));
    }
    {
        std::vector<int> v{0, -1, 4};
        sort(v);
        assert((v == std::vector<int>{-1, 0, 4}));
    }
}

int main() {
    run_all(bubble_sort);
    run_all(selection_sort);
    run_all(insertion_sort);
    run_all(merge_sort);
    run_all(quick_sort);
}
