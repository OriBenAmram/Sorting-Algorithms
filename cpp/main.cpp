#include <iostream>
#include <vector>
#include "util.hpp"
#include "algorithms/bubble.hpp"
#include "algorithms/selection.hpp"
#include "algorithms/insertion.hpp"
#include "algorithms/merge.hpp"
#include "algorithms/quick.hpp"
#include "algorithms/heap.hpp"

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

    return 0;
}
