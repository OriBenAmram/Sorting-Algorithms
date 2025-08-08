# Sorting Algorithms in C, C++, and Python

This repository gathers the implementations of these algorithms in three programming languages — **C**, **C++**, and **Python** — both for practice and to provide a resource for anyone preparing for relevant exams or interviews. Good luck!

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

*(More algorithms will be added each day.)*

---

## Noteworthy Commands & Concepts

### **C – `#pragma once`**
Ensures the header file is included only once during compilation, preventing multiple-definition errors.  
Shorter and less error-prone than traditional `#ifndef / #define / #endif` include guards.

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
