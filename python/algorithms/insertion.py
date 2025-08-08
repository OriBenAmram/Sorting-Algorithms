from util import swap_int

def insertion_sort(arr):
    n = len(arr)
    if n < 2:
        return
    for i in range(1, n):
        j = i
        while j > 0 and arr[j - 1] > arr[j]:
            swap_int(arr, j, j - 1)
            j -= 1
