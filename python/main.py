from util import print_array
from algorithms.bubble import bubble_sort
from algorithms.selection import selection_sort
from algorithms.insertion import insertion_sort
from algorithms.merge import merge_sort
from algorithms.quick import quick_sort
from algorithms.heap import heap_sort

def merge_sort_adapter(arr):
    if arr:
        merge_sort(arr, 0, len(arr) - 1)

def run_sort(name, func):
    arr = [64, 34, 25, 12, 22, 11, 90]
    print(f"{name} sort:")
    print_array(arr)
    func(arr)
    print_array(arr)
    print()

if __name__ == "__main__":
    run_sort("Bubble", bubble_sort)
    run_sort("Selection", selection_sort)
    run_sort("Insertion", insertion_sort)
    run_sort("Merge", merge_sort_adapter)
    run_sort("Quick", quick_sort)
    run_sort("Heap", heap_sort)
