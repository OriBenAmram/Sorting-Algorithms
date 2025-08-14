def heap_sort(numbers):
    """In-place Heap Sort (max-heap, sift-down)."""
    if not numbers or len(numbers) < 2:
        return

    n = len(numbers)

    def sift_down(start, end):
        root = start
        while True:
            child = 2 * root + 1            # left child index
            if child > end:                  # no children
                break
            if child + 1 <= end and numbers[child] < numbers[child + 1]:
                child += 1                   # right child is larger
            if numbers[root] < numbers[child]:
                numbers[root], numbers[child] = numbers[child], numbers[root]
                root = child                 # keep sifting down
            else:
                break

    # 1) Build max-heap bottom-up
    for start in range((n - 2) // 2, -1, -1):
        sift_down(start, n - 1)

    # 2) Repeatedly move max to the end and fix the heap
    for end in range(n - 1, 0, -1):
        numbers[0], numbers[end] = numbers[end], numbers[0]
        sift_down(0, end - 1)
