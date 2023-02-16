#include <iostream>
#include <chrono>
#include <fstream>
#include "sorting_algorithms.h"

bool checkCorrectness(const int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void copyElements(const int a[], int b[], int n) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
}

void launchCorrectnessChecker(const int initial_array[], int n, std::ofstream *output) {
    const int count_of_tests = 13;
    const std::string tests[count_of_tests] { "Selection Sort",
                                              "Bubble Sort",
                                              "Bubble Sort (Iverson 1)",
                                              "Bubble Sort (Iverson 1+2)",
                                              "Insertion Sort",
                                              "Binary Insertion Sort",
                                              "Stable Counting Sort",
                                              "Radix Sort",
                                              "Merge Sort",
                                              "Quick Sort",
                                              "Heap Sort",
                                              "Shell Sort (Tsiur Sequence)",
                                              "Shell Sort (Shell Sequence)"
    };
    int successful_tests = 0, failed_tests = 0;
    int current_test = 0;

    *output << "--------------------[START CORRECTNESS TEST]--------------------\n\n";

    int array[n];

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    selectionSort(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    bubbleSort(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    bubbleSortIversonFirst(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    bubbleSortIversonFirstAndSecond(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    insertionSort(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    binaryInsertionSort(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    stableCountingSort(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    radixSort10(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    mergeSort(array, 0, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    quickSort(array, 0, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    heapSort(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    shellSortTsiurSequence(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    shellSortShellSequence(array, n);
    for (int i : array) {
        *output << i << " ";
    }
    *output << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        *output << "-FAIL-\n";
    }

    *output << "\n\n";
    *output << "--------------------[FINISH CORRECTNESS TEST]--------------------\n";
    *output << "SUCCESSFUL TESTS: " << successful_tests << "/" << count_of_tests << "\n";
    *output << "FAILED TESTS: " << failed_tests << "/" << count_of_tests << "\n\n";
}

void launchTimeChecker(const int initial_array[], int n, std::ofstream *output) {
    const int count_of_repeats = 10;
    const int count_of_tests = 13;
    const std::string tests[count_of_tests] { "Selection Sort",
                                              "Bubble Sort",
                                              "Bubble Sort (Iverson 1)",
                                              "Bubble Sort (Iverson 1+2)",
                                              "Insertion Sort",
                                              "Binary Insertion Sort",
                                              "Stable Counting Sort",
                                              "Radix Sort",
                                              "Merge Sort",
                                              "Quick Sort",
                                              "Heap Sort",
                                              "Shell Sort (Tsiur Sequence)",
                                              "Shell Sort (Shell Sequence)"
    };
    int current_test = 0;

    *output << "--------------------[START TIME TEST]--------------------\n\n";

    long long nanoseconds;

    int array[n];

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        selectionSort(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        bubbleSort(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        bubbleSortIversonFirst(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        bubbleSortIversonFirstAndSecond(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        insertionSort(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        binaryInsertionSort(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        stableCountingSort(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        radixSort10(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        mergeSort(array, 0, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        quickSort(array, 0, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        heapSort(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        shellSortTsiurSequence(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";

    *output << tests[current_test++] << "\n";
    nanoseconds = 0;
    for (int i = 0; i < 10; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        shellSortShellSequence(array, n);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << "Average " << nanoseconds / count_of_repeats << " ns." << "\n";

    *output << "\n\n";
    *output << "--------------------[FINISH TIME TEST]--------------------\n\n";
}
