#ifndef SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_TEST_H_
#define SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_TEST_H_

/// Вывод в файл корректности результатов всех сортировок заголовка \b sorting_algorithms.h .
void launchCorrectnessChecker(const int initial_array[], int n, std::ofstream *output, const std::string &info);

/// Вывод в файл замеров времени работы всех сортировок заголовка \b sorting_algorithms.h .
void launchTimeChecker(const int initial_array[], int n, std::ofstream *output, const std::string &info);

/// Вывод в файл массива до и после сортировки пузырьком.
void launchArrayViewer(const int initial_array[], int n, std::ofstream *output, const std::string &info);

#endif //SORTING_WORKSHOP_SORTING_WORKSHOP_LIBRARY_TEST_H_
