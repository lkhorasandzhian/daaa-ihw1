#include <iostream>
#include <fstream>
#include "test.h"
#include "array_generator.h"

void startProcess() {
    std::ofstream correctness_output, viewer_output;
    int *initial_arrays[4];

    correctness_output.open("../../../test_correctness.txt");
    viewer_output.open("../../../test_view.txt");
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:
                initial_arrays[i] = generateRandomizedArray(4100, 0, 5);
                launchCorrectnessChecker(initial_arrays[i], 4100, &correctness_output, "Randomized 5");
                launchArrayViewer(initial_arrays[i], 4100, &viewer_output, "Randomized 5");
                break;
            case 1:
                initial_arrays[i] = generateRandomizedArray(4100, 0, 4000);
                launchCorrectnessChecker(initial_arrays[i], 4100, &correctness_output, "Randomized 4000");
                launchArrayViewer(initial_arrays[i], 4100, &viewer_output, "Randomized 4000");
                break;
            case 2:
                initial_arrays[i] = generateAlmostSortedArray(4100, 1, 4100);
                launchCorrectnessChecker(initial_arrays[i], 4100, &correctness_output, "Almost sorted");
                launchArrayViewer(initial_arrays[i], 4100, &viewer_output, "Almost sorted");
                break;
            case 3:
                initial_arrays[i] = generateReverseSortedArray(4100, 1, 4100);
                launchCorrectnessChecker(initial_arrays[i], 4100, &correctness_output, "Reverse sorted");
                launchArrayViewer(initial_arrays[i], 4100, &viewer_output, "Reverse sorted");
                break;
            default:break;
        }
    }
    viewer_output.close();
    correctness_output.close();

    std::ofstream time_output, counter_output;
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
        time_output.open("../../../test_time_" + std::to_string(i) + ".csv");
        counter_output.open("../../../test_counter_" + std::to_string(i) + ".csv");
        for (; size <= finish; size += step) {
            // Randomized in range [0,5].
            launchTimeChecker(initial_arrays[0], size, &time_output, "Randomized 5;" + std::to_string(size) + ";");
            launchCounterChecker(initial_arrays[0], size, &counter_output, "Randomized 5;" + std::to_string(size) + ";");

            // Randomized in range [0,4000].
            launchTimeChecker(initial_arrays[1], size, &time_output, "Randomized 4000;" + std::to_string(size) + ";");
            launchCounterChecker(initial_arrays[1], size, &counter_output, "Randomized 4000;" + std::to_string(size) + ";");

            // Almost sorted in range [1,4100].
            launchTimeChecker(initial_arrays[2], size, &time_output, "Almost sorted;" + std::to_string(size) + ";");
            launchCounterChecker(initial_arrays[2], size, &counter_output, "Almost sorted;" + std::to_string(size) + ";");

            // Reverse sorted in range [1,4100].
            launchTimeChecker(initial_arrays[3], size, &time_output, "Reverse sorted;" + std::to_string(size) + ";");
            launchCounterChecker(initial_arrays[3], size, &counter_output, "Reverse sorted;" + std::to_string(size) + ";");
        }
        counter_output.close();
        time_output.close();
    }

    for (int* &initial_array : initial_arrays) {
        delete[] initial_array;
    }
}
