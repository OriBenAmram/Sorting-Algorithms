from util import swap_int

def bubble_sort(arr):
    n = len(arr)
    if n < 2:
        return
    for i in range(n - 1):
        swapped = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                swap_int(arr, j, j + 1)
                swapped = True
        if not swapped:
            break
