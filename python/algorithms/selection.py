from util import swap_int

def selection_sort(arr):
    n = len(arr)
    if n < 2:
        return
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        if min_index != i:
            swap_int(arr, i, min_index)
