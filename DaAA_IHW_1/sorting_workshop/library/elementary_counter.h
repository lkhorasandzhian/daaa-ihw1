#ifndef SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ELEMENTARY_COUNTER_H_
#define SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ELEMENTARY_COUNTER_H_

/// Счётчик элементарных операций в сортировках из заголовка \b sorting_algorithms.h .
extern unsigned long long global_counter;

/// 1) Сортировка выбором.
void selectionSortCounter(int arr[], int n);

/// 2) Сортировка пузырьком.
void bubbleSortCounter(int arr[], int n);

/// 3) Сортировка пузырьком с условием Айверсона 1.
void bubbleSortIversonFirstCounter(int arr[], int n);

/// 4) Сортировка пузырьком с условием Айверсона 1+2.
void bubbleIversonFirstAndSecondCounter(int arr[], int n);

/// 5) Сортировка простыми вставками.
void insertionSortCounter(int arr[], int n);

/// 6) Сортировка бинарными вставками.
void binaryInsertionSortCounter(int arr[], int n);

/// 7) Сортировка подсчётом (устойчивая).
void stableCountingSortCounter(int arr[], int n);

/// 8) Цифровая сортировка.
void radixSort10Counter(int arr[], int n);

/// 9) Сортировка слиянием.
void mergeSortCounter(int array[], int begin, int end);

/// 10) Быстрая сортировка (первый опорный).
void quickSortCounter(int arr[], int low, int high);

/// 11) Пирамидальная сортировка.
void heapSortCounter(int arr[], int n);

/// 12) Сортировка Шелла (последовательность Циура).
void shellSortTsiurSequenceCounter(int arr[], int n);

/// 13) Сортировка Шелла (последовательность Шелла).
void shellSortShellSequenceCounter(int arr[], int n);

#endif //SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_ELEMENTARY_COUNTER_H_
