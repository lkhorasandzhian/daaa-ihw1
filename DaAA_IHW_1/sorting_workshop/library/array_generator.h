#ifndef SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_
#define SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_

/// Создаёт массив, заполненный случайными числами в диапазоне [lower_bound;upper_bound].
int *generateRandomizedArray(int size, int lower_bound, int upper_bound);

/// Создаёт почти отсортированный массив, заполненный случайными числами в диапазоне [lower_bound;upper_bound].
int *generateAlmostSortedArray(int size, int lower_bound, int upper_bound);

/// Создаёт отсортированный по убыванию массив, заполненный случайными числами в диапазоне [lower_bound;upper_bound].
int *generateReverseSortedArray(int size, int lower_bound, int upper_bound);

#endif //SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_
