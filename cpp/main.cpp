#include <iostream>
#include <vector>
#include "util.hpp"
#include "algorithms/bubble.hpp"
#include "algorithms/selection.hpp"
#include "algorithms/insertion.hpp"
#include "algorithms/merge.hpp"
#include "algorithms/quick.hpp"
#include "algorithms/heap.hpp"
#include "algorithms/counting.hpp"
#include "algorithms/radix.hpp"
#include "algorithms/bucket.hpp"

int main() {
    std::vector<int> a1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Bubble sort:\n";
    print_array(a1);
    bubble_sort(a1);
    print_array(a1);

    std::vector<int> a2 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "\nSelection sort:\n";
    print_array(a2);
    selection_sort(a2);
    print_array(a2);

    std::vector<int> a3 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "\nInsertion sort:\n";
    print_array(a3);
    insertion_sort(a3);
    print_array(a3);

    std::vector<int> a4 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "\nMerge sort:\n";
    print_array(a4);
    merge_sort(a4);
    print_array(a4);

    std::vector<int> a5 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "\nQuick sort:\n";
    print_array(a5);
    quick_sort(a5);
    print_array(a5);

    std::vector<int> a6 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "\nHeap sort:\n";
    print_array(a6);
    heap_sort(a6);
    print_array(a6);

    
    std::vector<int> a7 = {5, -3, 7, 0, -3, 5, 2};
    std::cout << "\nCounting sort:\n";
    print_array(a7);
    counting_sort(a7);
    print_array(a7);

    std::vector<int> a8 = {170, 45, 75, -90, -802, 24, 2, 66};
    std::cout << "\nRadix sort:\n";
    print_array(a8);
    radix_sort(a8);
    print_array(a8);

    std::vector<double> a9 = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    std::cout << "\nBucket sort:\n";
    for (double x : a9) std::cout << x << " ";
    std::cout << "\n";
    bucket_sort(a9);
    for (double x : a9) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
