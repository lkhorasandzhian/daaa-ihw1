#ifndef SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_
#define SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_

/// Создаёт массив, заполненный случайными числами в диапазоне [lower_bound;upper_bound].
int *generateRandomizedArray(int size, int lower_bound, int upper_bound);

/// Создаёт почти отсортированный массив, заполненный числами от 1 до size.
int *generateAlmostSortedArray(int size);

/// Создаёт отсортированный по убыванию массив, заполненный числами от 1 до size.
int *generateReverseSortedArray(int size);

#endif //SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ARRAY_GENERATOR_H_
