#include <random>

int *generateRandomizedArray(int size, int lower_bound, int upper_bound) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

    int *array = new int[size];

    for (int i = 0; i < size; ++i) {
        array[i] = dist(eng);
    }

    return array;
}

int *generateAlmostSortedArray(int size) {
    int *array = new int[size];

    for (int number = 0; number < size; ++number) {
        array[number] = number + 1;
        if (number % 75 == 0) {
            std::swap(array[number], array[number - 70]);
        }
    }

    return array;
}

int *generateReverseSortedArray(int size) {
    int *forward_array = new int[size];

    for (int number = size - 1; number >= 0; --number) {
        forward_array[size - 1 - number] = number + 1;
    }

    return forward_array;
}
