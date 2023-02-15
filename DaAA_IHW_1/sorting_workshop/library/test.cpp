#include <iostream>
#include <chrono>
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

void launchCorrectnessChecker(const int initial_array[], int n) {
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

    std::cout << "--------------------[START CORRECTNESS TEST]--------------------\n\n";

    int array[n];

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    selectionSort(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    bubbleSort(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    bubbleSortIversonFirst(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    bubbleSortIversonFirstAndSecond(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    insertionSort(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    binaryInsertionSort(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    stableCountingSort(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    radixSort10(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    mergeSort(array, 0, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    quickSort(array, 0, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    heapSort(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    shellSortTsiurSequence(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    shellSortShellSequence(array, n);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        std::cout << "-SUCCESS-\n";
    } else {
        ++failed_tests;
        std::cout << "-FAIL-\n";
    }

    std::cout << "\n\n";
    std::cout << "--------------------[FINISH CORRECTNESS TEST]--------------------\n";
    std::cout << "SUCCESSFUL TESTS: " << successful_tests << "/" << count_of_tests << "\n";
    std::cout << "FAILED TESTS: " << failed_tests << "/" << count_of_tests << "\n\n";
}

void launchTimeChecker(const int initial_array[], int n) {
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

    std::cout << "--------------------[START TIME TEST]--------------------\n\n";

    int array[n];

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    auto start_time_point =  std::chrono::high_resolution_clock::now();
    selectionSort(array, n);
    auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    long long milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    bubbleSort(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    bubbleSortIversonFirst(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    bubbleSortIversonFirstAndSecond(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    insertionSort(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    binaryInsertionSort(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    stableCountingSort(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    radixSort10(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    quickSort(array, 0, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    heapSort(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    shellSortTsiurSequence(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";

    std::cout << tests[current_test++] << "\n";
    copyElements(initial_array, array, n);
    start_time_point = std::chrono::high_resolution_clock::now();
    shellSortShellSequence(array, n);
    elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
    milliseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count();
    std::cout << milliseconds << " ms." << "\n";

    std::cout << "\n\n";
    std::cout << "--------------------[FINISH TIME TEST]--------------------\n\n";
}
