def quick_sort(numbers):
    """In-place Quick Sort using Lomuto partition scheme."""
    if not numbers or len(numbers) < 2:
        return

    def partition(nums, left_index, right_index):
        pivot_value = nums[right_index]
        i = left_index - 1
        for j in range(left_index, right_index):
            if nums[j] <= pivot_value:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1], nums[right_index] = nums[right_index], nums[i + 1]
        return i + 1

    def quick_sort_recursive(nums, left_index, right_index):
        if left_index >= right_index:
            return
        pivot_position = partition(nums, left_index, right_index)
        quick_sort_recursive(nums, left_index, pivot_position - 1)
        quick_sort_recursive(nums, pivot_position + 1, right_index)

    quick_sort_recursive(numbers, 0, len(numbers) - 1)
