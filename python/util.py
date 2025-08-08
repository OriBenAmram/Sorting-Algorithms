def print_array(arr):
    print(" ".join(str(x) for x in arr))

def swap_int(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
