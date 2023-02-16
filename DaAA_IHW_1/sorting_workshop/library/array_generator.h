#ifndef SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_
#define SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_

/// Generates array filled with random numbers in range [lower_bound;upper_bound].
int *generateRandomizedArray(int size, int lower_bound, int upper_bound);

/// Generates almost sorted array filled with random numbers in range [lower_bound;upper_bound].
int *generateAlmostSortedArray(int size, int lower_bound, int upper_bound);

/// Generates reverse sorted array filled with random numbers in range [lower_bound;upper_bound].
int *generateReverseSortedArray(int size, int lower_bound, int upper_bound);

#endif //SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_
