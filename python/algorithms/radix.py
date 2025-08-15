def radix_sort(arr):
    """
    LSD Radix Sort for integers (supports negatives).

    Steps:
      1) Trivial case: len<2 -> return.
      2) Split into negatives and non-negatives.
      3) Run LSD radix on abs(negatives) and on non-negatives separately.
      4) For negatives: reverse the sorted absolutes and re-apply the minus.
      5) Concatenate (negatives first), write back in-place.

    Notes:
      - Base = 256 (one byte). Each pass is a stable counting sort on that byte.
      - Pass count = number of bytes needed by the current partition's max.
    """
    n = len(arr)
    if n < 2:
        return

    # (2) split
    neg_abs = [-x for x in arr if x < 0]   # store absolute values
    pos     = [x  for x in arr if x >= 0]

    # (3) radix on each non-negative sub-array
    pos     = _lsd_radix_nonneg(pos)
    neg_abs = _lsd_radix_nonneg(neg_abs)

    # (4) rebuild negatives: larger absolute -> more negative (smaller number)
    neg = [-x for x in reversed(neg_abs)]

    # (5) write back
    arr[:] = neg + pos


def _lsd_radix_nonneg(a):
    """Stable LSD radix for non-negative Python ints using base 256."""
    if not a:
        return []

    base = 256
    n = len(a)
    # Number of 8-bit passes; bit_length==0 for 0, so ensure at least 1 pass.
    maxv = max(a)
    passes = max(1, (maxv.bit_length() + 7) // 8)

    src = a[:]           # we won't mutate the caller's list in this helper
    buf = [0] * n

    for p in range(passes):
        shift = 8 * p
        count = [0] * base

        # Count occurrences of this byte
        for x in src:
            count[(x >> shift) & 0xFF] += 1

        # Prefix sums -> end positions (stable indices)
        for i in range(1, base):
            count[i] += count[i - 1]

        # Stable placement: walk from right to left
        for i in range(n - 1, -1, -1):
            d = (src[i] >> shift) & 0xFF
            count[d] -= 1
            buf[count[d]] = src[i]

        # Next pass reads from buf
        src, buf = buf, src

    return src
