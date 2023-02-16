#include <iostream>
#include <fstream>
#include <chrono>
#include "test.h"
#include "array_generator.h"

void startProcess() {
    auto start_process =  std::chrono::steady_clock::now();
    std::ofstream output;
    for (int i = 1; i <= 10; ++i) {
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
}
