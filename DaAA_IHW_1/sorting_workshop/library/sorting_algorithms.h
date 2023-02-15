#ifndef SORTING_WORKSHOP_LIBRARY_SORTING_ALGORITHMS_H_
#define SORTING_WORKSHOP_LIBRARY_SORTING_ALGORITHMS_H_

/// 1) Сортировка выбором.
void selectionSort(int arr[], int n);

/// 2) Сортировка пузырьком.
void bubbleSort(int arr[], int n);

/// 3) Сортировка пузырьком с условием Айверсона 1.
void bubbleSortIversonFirst(int arr[], int n);

/// 4) Сортировка пузырьком с условием Айверсона 1+2.
void bubbleSortIversonFirstAndSecond(int arr[]);

/// 5) Сортировка простыми вставками.
void insertionSort(int arr[], int n);

/// 6) Сортировка бинарными вставками.
void binaryInsertionSort(int arr[], int n);

/// 7) Сортировка подсчётом (устойчивая).
void stableCountingSort(int arr[], int n);

/// 8) Цифровая сортировка.
void radixSort10(int arr[], int n);

/// 9) Сортировка слиянием.
void mergeSort(int array[], int begin, int end);

/// 10) Быстрая сортировка (первый опорный).
void quickSort(int arr[], int low, int high);

/// 11) Пирамидальная сортировка.
void heapSort(int arr[], int n);

/// 12) Сортировка Шелла (последовательность Циура).
void shellSortTsiurSequence(int arr[], int n);

/// 13) Сортировка Шелла (последовательность Шелла).
void shellSortShellSequence(int arr[], int n);

#endif //SORTING_WORKSHOP_LIBRARY_SORTING_ALGORITHMS_H_
