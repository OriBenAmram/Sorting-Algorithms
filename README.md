# Sorting Algorithms in C, C++, and Python

This repository presents a collection of sorting algorithms implemented in **C**, **C++**, and **Python**, both for practice and as a resource for anyone preparing for relevant exams or interviews. Sections **[7–9](#7-counting-sort)** cover **linear-time** algorithms that are efficient when certain assumptions about the input hold (bounded key range, fixed-width digits, or roughly uniform distribution). For these three, the in-code comments have been expanded to explain each non-trivial step, making the logic easier to follow and debug.

The README is structured in three main parts: first, a **[Running Tests](#running-tests)** section that explains how to compile and execute the tests for each language; second, detailed **[Algorithm Explanations](#algorithms)** including time and space complexities; and finally, a **[Notes and Concepts](#noteworthy-commands--concepts)** section covering additional commands and programming techniques that were not part of my formal coursework, included so classmates, fellow students, and other readers can fully understand the code.

---

## Running Tests
From the project root: 

**C**
```bash
gcc -std=c11 -Wall -Wextra -O2 -I c -I c/algorithms `
  tests/test_sorts.c c/util.c c/algorithms/*.c `
  -o test_c_sorts.exe

.\test_c_sorts.exe

```

**C++**
```bash
g++ -std=c++17 -Wall -Wextra -O2 -I cpp -I cpp/algorithms `
  tests/test_sorts.cpp cpp/util.cpp cpp/algorithms/*.cpp `
  -o test_cpp_sorts.exe

.\test_cpp_sorts.exe

```

**Python**
```bash
python -m pytest tests/test_sorts.py -q
```

---

## Algorithms

### 1. Bubble Sort
**How it works:** Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. Large elements "bubble" to the end with each pass.  

**Time Complexity:**  
- Best: O(n) (already sorted)  
- Average: O(n²)  
- Worst: O(n²)  
**Space Complexity:** O(1)  
*The time complexity is O(n²) in the average and worst cases because two nested loops compare and potentially swap elements for most positions in the array.*

---

### 2. Selection Sort
**How it works:** Finds the smallest element in the unsorted portion and swaps it with the first unsorted element.  

**Time Complexity:**  
- Best: O(n²)  
- Average: O(n²)  
- Worst: O(n²)  
**Space Complexity:** O(1)  
*The time complexity is O(n²) in all cases because for each position in the array, the algorithm scans the entire remaining unsorted portion to find the smallest element.*

---

### 3. Insertion Sort
**How it works:** Builds the sorted list one element at a time by inserting each new element into the correct position in the sorted portion.  

**Time Complexity:**  
- Best: O(n) (already sorted)  
- Average: O(n²)  
- Worst: O(n²)  
**Space Complexity:** O(1)  
*The time complexity is O(n²) in the average and worst cases because each new element may need to be compared with and shifted past almost all previously sorted elements.*

---

### 4. Merge Sort
**How it works:** Recursively divides the array into halves until each subarray has one element, then merges the subarrays back together in sorted order using a helper merge function.

**Time Complexity:**  
- Best: O(n log n)  
- Average: O(n log n)  
- Worst: O(n log n)  
**Space Complexity:** O(n) (due to temporary arrays for merging)  
*The time complexity is O(n log n) in all cases because the array is repeatedly divided into halves (log n splits) and each merge operation takes O(n) time.*

---

### 5. Quick Sort
**How it works:** Picks a pivot and partitions the array so that elements ≤ pivot are on the left and > pivot on the right, then recursively sorts the partitions.

**Time Complexity:**  
- Best: O(n log n)  
- Average: O(n log n)  
- Worst: O(n²) (e.g., already sorted with bad pivot choice)  
**Space Complexity:** O(log n) (recursion stack)  
*Fast in practice with good pivot choices; here we use the classic Lomuto partition for clarity.*

---

### 6. Heap Sort
**How it works:** Builds a **max-heap** from the array (a complete binary tree where each parent is greater than or equal to its children). Once the heap is built, repeatedly swaps the root (maximum) with the last element in the unsorted portion, reduces the heap size by one, and restores the heap property by sifting down the new root.  

**Time Complexity:**  
- Best: O(n log n)  
- Average: O(n log n)  
- Worst: O(n log n)  
**Space Complexity:** O(1)  
*Runs in O(n log n) in all cases because building the heap takes O(n) and each of the n−1 extractions takes O(log n). It is an in-place algorithm but not stable.*

---

### 7. Counting Sort  
**How it works:** For integer keys in a bounded range `[min, max]`, allocate a zeroed **count array** of size `R = max − min + 1`, tally frequencies, compute **prefix sums** to get final positions, then place items **stably** by scanning the input from right to left into an output buffer and copy back.  
**Typical steps:** (1) handle trivial cases, (2) find min/max, (3) create zeroed count array, (4) tally, (5) prefix sums, (6) stable placement into `out`, (7) write back.  

**Time Complexity:**  
- Best: O(n + R)  
- Average: O(n + R)  
- Worst: O(n + R)  

**Space Complexity:** O(R) (plus O(n) if using a separate output buffer)  
*Linear when the key range `R` is O(n); stable; ideal for integers with a small known range (negatives supported via offset by `min`).*  

---

### 8. Radix Sort (LSD)  
**How it works:** Repeatedly applies a **stable counting sort** to one digit at a time, from **least** significant to most significant. Stability preserves the ordering imposed by earlier passes, so after the final pass the array is fully sorted. For signed integers, either offset the key space or sort non-negatives and the absolute values of negatives separately and recombine.  

**Time Complexity:**  
- Best: O(w · (n + B))  
- Average: O(w · (n + B))  
- Worst: O(w · (n + B))  
where `w` is the number of digits (e.g., bytes for base `B = 256`). With fixed word size and base, this is effectively **O(n)**.  

**Space Complexity:** O(n + B)  
*Non-comparison, stable; great for fixed-width integers or strings when you can choose a convenient base.*  

*Note:* In the C implementation, Bucket Sort is written for `double` arrays to match its typical use case for floating-point data. It is therefore excluded from the integer-based automated test harness.

---

### 9. Bucket Sort  
**How it works:** Partition the value range into `k` buckets (commonly `k ≈ n`). Map each element to a bucket by its **normalized position** in the range, **sort each bucket** (e.g., with Timsort), and then concatenate the buckets. Works best when the data are **roughly uniform** over an interval (e.g., floats in `[0,1)`).  

**Time Complexity:**  
- Expected: O(n) (uniform-ish data; small buckets)  
- Worst: O(n log n) (if many values fall into a few buckets)  

**Space Complexity:** O(n + k)  
*Effective for real numbers drawn from a near-uniform distribution; choose `k` to balance bucket size and overhead (using `k = n` is a strong default).*  

---

## Noteworthy Commands & Concepts

### **C – `#pragma once`**
Ensures the header file is included only once during compilation, preventing multiple-definition errors.  
Shorter and less error-prone than traditional `#ifndef / #define / #endif` include guards.

---

### **C / C++ – Internal Linkage for Private Helpers**
In C, declaring a function as `static` at the top level of a `.c` file gives it **internal linkage** — it can only be used within that file. This is useful for keeping helper functions private to an implementation, preventing name clashes, and keeping the public API clean.  
In C++, the same effect can be achieved with `static` or by placing the helper function inside an **anonymous namespace**. Anything in an anonymous namespace is visible only in that `.cpp` file.  
In this project, for example, the `merge` function in `merge.c` is `static`, and in C++ implementations some helpers are placed in an anonymous namespace for the same reason.


---

### **C – `#ifndef / #define / #endif` Include Guards**
Preprocessor directives that prevent a header file from being included more than once.  
Example:
```c
#ifndef HEADER_NAME
#define HEADER_NAME
// header content
#endif
```
In this project I chose to use #pragma once because it’s shorter, less prone to mistakes, and can be a bit more efficient — the compiler can quickly skip reading the file again if it already handled it earlier. I also added the classic #ifndef / #define / #endif guards I learned in school, so I could try both methods and compare them.

---
