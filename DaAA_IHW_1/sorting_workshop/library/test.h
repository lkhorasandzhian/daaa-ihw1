#ifndef SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_TEST_H_
#define SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_TEST_H_

/// Вывод в консоль результатов всех сортировок заголовка \b sorting_algorithms.h .
void launchCorrectnessChecker(const int initial_array[], int n, std::ofstream *output);

/// Замер времени работы всех сортировок заголовка \b sorting_algorithms.h .
void launchTimeChecker(const int initial_array[], int n, std::ofstream *output);

#endif //SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_TEST_H_
