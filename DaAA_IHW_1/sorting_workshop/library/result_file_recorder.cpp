#include <iostream>
#include <fstream>
#include <chrono>
#include "test.h"
#include "array_generator.h"

void startProcess() {
    auto start_process =  std::chrono::steady_clock::now();
    std::ofstream output;
    int *initial_arrays[4];

    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:
                initial_arrays[i] = generateRandomizedArray(4100, 0, 5);
                break;
            case 1:
                initial_arrays[i] = generateRandomizedArray(4100, 0, 4000);
                break;
            case 2:
                initial_arrays[i] = generateAlmostSortedArray(4100, 0, 4100);
                break;
            case 3:
                initial_arrays[i] = generateReverseSortedArray(4100, 1, 4100);
                break;
            default:break;
        }
    }

    for (int i = 1; i <= 2; ++i) {
        int size, finish, step;
        if (i == 1) {
            size = 50;
            finish = 300;
            step = 50;
        } else {
            size = 100;
            finish = 4100;
            step = 100;
        }
        output.open("../../../test_" + std::to_string(i) + ".csv");
        for (; size < finish; size += step) {
            // Randomized in range [0,5].
            launchTimeChecker(initial_arrays[0], size, &output, "Randomized;" + std::to_string(size) + ";[0,5];");

            // Randomized in range [0,4000].
            launchTimeChecker(initial_arrays[1], size, &output, "Randomized;" + std::to_string(size) + ";[0,4000];");

            // Almost sorted in range [0,4000].
            launchTimeChecker(initial_arrays[2], size, &output, "Almost sorted;" + std::to_string(size) + ";[0,4000];");

            // Reverse sorted in range [1,4100].
            launchTimeChecker(initial_arrays[3], size, &output, "Reverse sorted;" + std::to_string(size) + ";[1,4100];");
        }
        output.close();
    }

    for (int* &initial_array : initial_arrays) {
        delete[] initial_array;
    }

    auto finish_process =  std::chrono::steady_clock::now();

    std::cout << '\a' << "Work time: ";
    std::cout << std::to_string(std::chrono::duration_cast<std::chrono::minutes>(finish_process - start_process).count()) + " min.\n";
}
