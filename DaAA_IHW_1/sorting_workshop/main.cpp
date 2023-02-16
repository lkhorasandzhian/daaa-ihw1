#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include "library/test.h"
#include "library/sorting_algorithms.h"

int *generateRandomizedArray(int size, int lower_bound, int upper_bound) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

    int *array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = dist(eng);
    }

    return array;
}

int *generateAlmostSortedArray(int size, int lower_bound, int upper_bound) {
    int *array = generateRandomizedArray(size, lower_bound, upper_bound);

    stableCountingSort(array, size);

    for (int step = 500; step < size - 500; step += 500) {
        for (int i = 0; i < 5; ++i) {
            std::swap(array[(step - 500) + i], array[step + i]);
        }
    }

    return array;
}

int *generateReverseSortedArray(int size, int lower_bound, int upper_bound) {
    int *forward_array = generateRandomizedArray(size, lower_bound, upper_bound);

    stableCountingSort(forward_array, size);

    int *backward_array = new int[size];
    for (int i = 0; i < size; ++i) {
        backward_array[i] = forward_array[i];
    }

    delete[] forward_array;

    return backward_array;
}

int main() {
    auto start_process =  std::chrono::steady_clock::now();
    std::ofstream output;
    for (int i = 1; i < 2; ++i) {
        output.open("../../../test" + std::to_string(i) + "_1.txt");
        for (int size = 50; size < 300; size += 50) {
            // Randomized in range [0;5].
            output << "Randomized in range [0;5]\n";
            int *initial_array = generateRandomizedArray(size, 0, 5);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;

            // Randomized in range [0;4000].
            output << "Randomized in range [0;4000]\n";
            initial_array = generateRandomizedArray(size, 0, 4000);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;

            // Almost sorted in range [0;4000].
            output << "Almost sorted in range [0;4000]\n";
            initial_array = generateAlmostSortedArray(size, 0, 4000);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;

            // Reverse sorted in range [1, 4100].
            output << "Reverse sorted in range [1;4100]\n";
            initial_array = generateReverseSortedArray(size, 1, 4100);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;
        }
        output.close();

        output.open("../../../test" + std::to_string(i) + "_2.txt");
        for (int size = 100; size < 4100; size += 100) {
            // Randomized in range [0;5].
            output << "Randomized in range [0;5]\n";
            int *initial_array = generateRandomizedArray(size, 0, 5);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;

            // Randomized in range [0;4000].
            output << "Randomized in range [0;4000]\n";
            initial_array = generateRandomizedArray(size, 0, 4000);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;

            // Almost sorted in range [0;4000].
            output << "Almost sorted in range [0;4000]\n";
            initial_array = generateAlmostSortedArray(size, 0, 4000);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;

            // Reverse sorted in range [1, 4100].
            output << "Reverse sorted in range [1;4100]\n";
            initial_array = generateReverseSortedArray(size, 1, 4100);
            launchTimeChecker(initial_array, size, &output);
            delete[] initial_array;
        }
        output.close();
    }
    std::cout << '\a' << "Work time: ";
    auto finish_process =  std::chrono::steady_clock::now();
    std::cout << std::to_string(std::chrono::duration_cast<std::chrono::seconds>(finish_process - start_process).count()) + " sec.\n";
    return 0;
}
