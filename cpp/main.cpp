#include <iostream>
#include <vector>
#include "util.hpp"
#include "algorithms/bubble.hpp"
#include "algorithms/selection.hpp"
#include "algorithms/insertion.hpp"

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

    return 0;
}
