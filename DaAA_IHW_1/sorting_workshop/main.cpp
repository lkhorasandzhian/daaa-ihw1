#include <iostream>
#include <random>
#include "library/test.h"

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

int main() {
    int *initial_array = generateRandomizedArray(5000, 50, 4100);
    launchCorrectnessChecker(initial_array, 1000);
    launchTimeChecker(initial_array, 1000);
    delete[] initial_array;
    return 0;
}
