#include <iostream>
#include <fstream>
#include "test.h"
#include "array_generator.h"

void startProcess() {
    std::ofstream output;
    int *initial_arrays[4];

    output.open("../../../test_correctness.txt");
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:
                initial_arrays[i] = generateRandomizedArray(4100, 0, 5);
                launchCorrectnessChecker(initial_arrays[i], 4100, &output, "Randomized 5");
                launchArrayViewer(initial_arrays[i], 4100, &output, "Randomized 5");
                break;
            case 1:
                initial_arrays[i] = generateRandomizedArray(4100, 0, 4000);
                launchCorrectnessChecker(initial_arrays[i], 4100, &output, "Randomized 4000");
                launchArrayViewer(initial_arrays[i], 4100, &output, "Randomized 4000");
                break;
            case 2:
                initial_arrays[i] = generateAlmostSortedArray(4100, 1, 4100);
                launchCorrectnessChecker(initial_arrays[i], 4100, &output, "Almost sorted");
                launchArrayViewer(initial_arrays[i], 4100, &output, "Almost sorted");
                break;
            case 3:
                initial_arrays[i] = generateReverseSortedArray(4100, 1, 4100);
                launchCorrectnessChecker(initial_arrays[i], 4100, &output, "Reverse sorted");
                launchArrayViewer(initial_arrays[i], 4100, &output, "Reverse sorted");
                break;
            default:break;
        }
    }
    output.close();

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
        for (; size <= finish; size += step) {
            // Randomized in range [0,5].
            launchTimeChecker(initial_arrays[0], size, &output, "Randomized 5;" + std::to_string(size) + ";");

            // Randomized in range [0,4000].
            launchTimeChecker(initial_arrays[1], size, &output, "Randomized 4000;" + std::to_string(size) + ";");

            // Almost sorted in range [1,4100].
            launchTimeChecker(initial_arrays[2], size, &output, "Almost sorted;" + std::to_string(size) + ";");

            // Reverse sorted in range [1,4100].
            launchTimeChecker(initial_arrays[3], size, &output, "Reverse sorted;" + std::to_string(size) + ";");
        }
        output.close();
    }

    for (int* &initial_array : initial_arrays) {
        delete[] initial_array;
    }
}
