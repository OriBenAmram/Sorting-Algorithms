#include <assert.h>
#include <string.h>
#include <stddef.h>
#include "../c/algorithms/bubble.h"
#include "../c/algorithms/selection.h"
#include "../c/algorithms/insertion.h"
#include "../c/algorithms/merge.h"
#include "../c/algorithms/quick.h"

static void run_all(void (*sort)(int*, size_t)) {
    int a0[] = {};
    sort(a0, 0);

    int a1[] = {1};
    sort(a1, 1);
    assert(a1[0] == 1);

    int a2[] = {3, 1, 2};
    sort(a2, 3);
    int e2[] = {1, 2, 3};
    assert(memcmp(a2, e2, sizeof a2) == 0);

    int a3[] = {0, -1, 4};
    sort(a3, 3);
    int e3[] = {-1, 0, 4};
    assert(memcmp(a3, e3, sizeof a3) == 0);
}

int main(void) {
    run_all(bubble_sort);
    run_all(selection_sort);
    run_all(insertion_sort);
    run_all(merge_sort);
    run_all(quick_sort);
    return 0;
}
