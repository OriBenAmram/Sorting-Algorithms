#include <stdio.h>
#include "util.h"
#include "algorithms/bubble.h"
#include "algorithms/selection.h"
#include "algorithms/insertion.h"
#include "algorithms/merge.h"
#include "algorithms/quick.h"
#include "algorithms/heap.h"

int main(void) {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Bubble sort:\n");
    print_array(arr1, n1);
    bubble_sort(arr1, n1);
    print_array(arr1, n1);

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\nSelection sort:\n");
    print_array(arr2, n2);
    selection_sort(arr2, n2);
    print_array(arr2, n2);

    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\nInsertion sort:\n");
    print_array(arr3, n3);
    insertion_sort(arr3, n3);
    print_array(arr3, n3);

    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("\nMerge sort:\n");
    print_array(arr4, n4);
    merge_sort(arr4, n4);
    print_array(arr4, n4);

    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("\nQuick sort:\n");
    print_array(arr5, n5);
    quick(arr5, n5);
    print_array(arr5, n5);

    int arr6[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("\nHeap sort:\n");
    print_array(arr6, n6);
    heap(arr6, n6);
    print_array(arr6, n6);

    return 0;
}
