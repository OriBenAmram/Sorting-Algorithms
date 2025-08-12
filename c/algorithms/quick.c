#include "quick.h"

static size_t partition(int* numbers, size_t left_index, size_t right_index)
{
    int pivot_value = numbers[right_index];
    size_t i = left_index;

    for (size_t j = left_index; j < right_index; ++j)
    {
        if (numbers[j] <= pivot_value)
        {
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            ++i;
        }
    }

    int temp = numbers[i];
    numbers[i] = numbers[right_index];
    numbers[right_index] = temp;

    return i;
}

static void quick_sort_recursive(int* numbers, size_t left_index, size_t right_index)
{
    if (left_index >= right_index)
        return;

    size_t pivot_position = partition(numbers, left_index, right_index);

    if (pivot_position > 0) // prevent size_t underflow
        quick_sort_recursive(numbers, left_index, pivot_position - 1);

    quick_sort_recursive(numbers, pivot_position + 1, right_index);
}

void quick_sort(int* numbers, size_t length)
{
    if (length < 2)
        return;

    quick_sort_recursive(numbers, 0, length - 1);
}
