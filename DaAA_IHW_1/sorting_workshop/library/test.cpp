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

void launchCorrectnessChecker(const int initial_array[], int n, std::ofstream *output, const std::string &info) {
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

    *output << "--------------------[START " + info + " TEST]--------------------\n\n";

    int array[n];

    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    selectionSort(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    bubbleSort(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    bubbleSortIversonFirst(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    bubbleSortIversonFirstAndSecond(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    insertionSort(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    binaryInsertionSort(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    stableCountingSort(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    radixSort10(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    mergeSort(array, 0, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    quickSort(array, 0, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    heapSort(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    shellSortTsiurSequence(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }


    *output << tests[current_test++] << ": ";
    copyElements(initial_array, array, n);
    shellSortShellSequence(array, n);
    if (checkCorrectness(array, n)) {
        ++successful_tests;
        *output << "SUCCESS\n";
    } else {
        ++failed_tests;
        *output << "FAIL\n";
    }

    *output << "\n--------------------[FINISH " + info + " TEST]--------------------\n";
    *output << "SUCCESSFUL TESTS: " << successful_tests << "/" << count_of_tests << "\n";
    *output << "FAILED TESTS: " << failed_tests << "/" << count_of_tests << "\n\n";
}

void launchTimeChecker(const int initial_array[], int n, std::ofstream *output, const std::string &info) {
    const int count_of_repeats = 100;
    const int count_of_tests = 13;
    const std::string tests[count_of_tests] { "Selection",
                                              "Bubble",
                                              "Bubble 1",
                                              "Bubble 1+2",
                                              "Insertion",
                                              "Bin. Insertion",
                                              "S. Counting",
                                              "Radix",
                                              "Merge",
                                              "Quick",
                                              "Heap",
                                              "Shell-Tsiur",
                                              "Shell"
    };
    int current_test = 0;

    long long nanoseconds;

    int array[n];

    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        selectionSort(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        bubbleSort(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        bubbleSortIversonFirst(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        bubbleSortIversonFirstAndSecond(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        insertionSort(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        binaryInsertionSort(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        stableCountingSort(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        radixSort10(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        mergeSort(array, 0, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        quickSort(array, 0, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        heapSort(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        shellSortTsiurSequence(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";


    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        copyElements(initial_array, array, n);
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        shellSortShellSequence(array, n);
        if (!checkCorrectness(array, n)) {
            exit(-1);
        }
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";
}

void launchArrayViewer(const int initial_array[], int n, std::ofstream *output, const std::string &info) {
    int array[n];

    copyElements(initial_array, array, n);

    *output << info << " before:\n";
    for (int i = 0; i < n; ++i) {
        *output << array[i] << " ";
    }
    *output << "\n\n";

    bubbleSort(array, n);

    *output << info << " after:\n";
    for (int i = 0; i < n; ++i) {
        *output << array[i] << " ";
    }
    *output << "\n\n";
}
