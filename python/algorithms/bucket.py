def bucket_sort(arr):
    """
    Bucket sort for numeric lists (ints or floats).
    Expected O(n) when data is roughly uniform; worst-case O(n log n).

    Steps:
      1) Trivial cases.
      2) Compute min/max and number of buckets k (use n).
      3) Place each x into bucket by normalized index in [0, k-1].
      4) Sort each bucket (Timsort) and concatenate (stable overall).
    """
    n = len(arr)
    if n < 2:
        return

    mn = min(arr)
    mx = max(arr)
    if mn == mx:
        return  # all equal

    k = n  # number of buckets; n is a good default
    buckets = [[] for _ in range(k)]

    # Normalized position -> bucket index in [0, k-1]
    denom = (mx - mn)
    for x in arr:
        # ratio in [0,1]; ensure max goes to last bucket
        idx = int((x - mn) / denom * (k - 1))
        buckets[idx].append(x)

    # Sort each bucket and write back
    i = 0
    for b in buckets:
        b.sort()
        for x in b:
            arr[i] = x
            i += 1
