def counting_sort(arr):
    """
    Stable counting sort for integers (supports negatives).

    Steps:
      1) Handle trivial input (0/1 item).
      2) Find global min/max to compute the value RANGE.
      3) Create an empty "count" array of size R = max - min + 1 (all zeros).
      4) Tally occurrences: count[x - min]++ for each x in arr.
      5) Prefix sums over count -> positions: count[i] accumulates elements <= i.
      6) Build output stably by scanning arr from RIGHT to LEFT.
      7) Copy output back into arr (in-place for callers).
    """
    n = len(arr)
    if n < 2:
        return

    mn = min(arr)
    mx = max(arr)
    R = mx - mn + 1

    # (3) index array initialized to zero
    count = [0] * R

    # (4) frequency tally (offset by mn so negatives work)
    for x in arr:
        count[x - mn] += 1

    # (5) prefix sums -> stable placement indices
    for i in range(1, R):
        count[i] += count[i - 1]

    # (6) stable fill of output by going backwards
    out = [0] * n
    for i in range(n - 1, -1, -1):
        k = arr[i] - mn
        count[k] -= 1                 # last free slot for this key
        out[count[k]] = arr[i]        # place arr[i]

    # (7) write back into the caller's list
    arr[:] = out
