#include "quick.hpp"
#include <vector>
#include <utility> // for std::swap

namespace
{
    int partition(std::vector<int>& numbers, int left_index, int right_index)
    {
        int pivot_value = numbers[right_index];
        int i = left_index - 1;

        for (int j = left_index; j < right_index; ++j)
        {
            if (numbers[j] <= pivot_value)
            {
                ++i;
                std::swap(numbers[i], numbers[j]);
            }
        }
        std::swap(numbers[i + 1], numbers[right_index]);
        return i + 1;
    }

    void quick_sort_recursive(std::vector<int>& numbers, int left_index, int right_index)
    {
        if (left_index >= right_index)
            return;

        int pivot_position = partition(numbers, left_index, right_index);
        quick_sort_recursive(numbers, left_index, pivot_position - 1);
        quick_sort_recursive(numbers, pivot_position + 1, right_index);
    }
}

void quick_sort(std::vector<int>& numbers)
{
    if (numbers.size() < 2)
        return;

    quick_sort_recursive(numbers, 0, numbers.size() - 1);
}
