#include <iostream>
#include "library/test.h"

int main() {
    int initial_array[10] { 12, 4, 3, 1, 15, 45, 33, 21, 10, 2 };
    launch(initial_array, 10);
    std::cout << "Hello, World!";
    return 0;
}
