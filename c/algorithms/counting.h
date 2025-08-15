#pragma once
#include <stddef.h>

// Stable counting sort for integers (supports negatives via offset).
void counting_sort(int* arr, size_t length);
