import pytest
from python.algorithms.bubble import bubble_sort
from python.algorithms.selection import selection_sort
from python.algorithms.insertion import insertion_sort
from python.algorithms.merge import merge_sort

def merge_sort_adapter(arr):
    if arr:
        merge_sort(arr, 0, len(arr) - 1)

@pytest.mark.parametrize("sort_func", [
    bubble_sort, selection_sort, insertion_sort, merge_sort_adapter
])
@pytest.mark.parametrize("data, expected", [
    ([], []),
    ([1], [1]),
    ([3, 1, 2], [1, 2, 3]),
    ([5, 5, 5], [5, 5, 5]),
    ([0, -1, 4], [-1, 0, 4]),
])
def test_sort_functions(sort_func, data, expected):
    arr = data.copy()
    sort_func(arr)
    assert arr == expected
