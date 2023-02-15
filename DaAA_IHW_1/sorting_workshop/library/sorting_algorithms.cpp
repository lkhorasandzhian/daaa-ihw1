#include <algorithm>

void selectionSort(int arr[], int n) {
    int i, j;
    int min_index;

    for (i = 0; i < n - 1; ++i) {
        min_index = i;

        for (j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            std::swap(arr[min_index], arr[i]);
        }
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortIversonFirst(int arr[], int n) {
    int i = 0, j;
    bool was_swapped;

    do {
        was_swapped = false;
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                was_swapped = true;
            }
        }
        ++i;
    } while (was_swapped);
}

void bubbleSortIversonFirstAndSecond(int arr[]) {
    int i = 0, j = 0;
    bool was_swapped;
    int last_swapped_index;

    do {
        was_swapped = false;
        last_swapped_index = 0;
        do {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                was_swapped = true;
                last_swapped_index = j;
            }
        } while (j < last_swapped_index);
        ++i;
        ++j;
    } while (was_swapped);
}

void insertionSort(int arr[], int n) {
    int i, j;
    int key;

    for (i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int leftBinarySearch(const int arr[], int key, int left, int right) {
    int middle;

    while (right - left > 1) {
        middle = left + (right - left) / 2;

        if (key > arr[middle]) {
            left = middle;
        } else {
            right = middle;
        }
    }

    return right;
}

void binaryInsertionSort(int arr[], int n) {
    int i, j;
    int position, current;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        current = arr[i];

        position = leftBinarySearch(arr, current, 0, j);

        while (j >= position) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = current;
    }
}

int getMin(const int arr[], int n) {
    int min = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int getMax(const int arr[], int n) {
    int max = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void stableCountingSort(int arr[], int n) {
    int lower_bound = getMin(arr, n), upper_bound = getMax(arr, n);
    int sorted_arr[n];
    const int k = upper_bound - lower_bound + 1;
    int counter[k];
    int i;

    for (i = 0; i < k; ++i) {
        counter[i] = 0;
    }

    for (i = 0; i < n; ++i) {
        ++counter[arr[i] - lower_bound];
    }

    for (i = 1; i < k; ++i) {
        counter[i] += counter[i - 1];
    }

    for (i = n - 1; i >= 0; --i) {
        --counter[arr[i] - lower_bound];
        sorted_arr[counter[arr[i] - lower_bound]] = arr[i];
    }

    for (i = 0; i < n; ++i) {
        arr[i] = sorted_arr[i];
    }
}

int getSelectedDigit10(int number, int position) {
    for (int i = 0; i < position; ++i) {
        number /= 10;
    }
    return number % 10;
}

void radixSort10(int arr[], int n) {
    int sorted_arr[n];
    int counter[10];
    int i, j;

    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 10; ++j) {
            counter[j] = 0;
        }

        for (j = 0; j < n; ++j) {
            ++counter[getSelectedDigit10(arr[j], i)];
        }

        for (j = 1; j < 10; ++j) {
            counter[j] += counter[j - 1];
        }

        for (j = n - 1; j >= 0; --j) {
            --counter[getSelectedDigit10(arr[j], i)];
            sorted_arr[counter[getSelectedDigit10(arr[j], i)]] = arr[j];
        }

        for (j = 0; j < n; ++j) {
            arr[j] = sorted_arr[j];
        }
    }
}

void merge(int array[], int left, int middle, int right) {
    int left_sub_array_size = middle - left + 1;
    int right_sub_array_size = right - middle;

    int *left_sub_array = new int[left_sub_array_size];
    int *right_sub_array = new int[right_sub_array_size];

    int i;

    for (i = 0; i < left_sub_array_size; ++i) {
        left_sub_array[i] = array[left + i];
    }
    for (i = 0; i < right_sub_array_size; ++i) {
        right_sub_array[i] = array[middle + 1 + i];
    }

    int left_sub_array_index = 0, right_sub_array_index = 0;
    int merged_array_index = left;

    while (left_sub_array_index < left_sub_array_size && right_sub_array_index < right_sub_array_size) {
        if (left_sub_array[left_sub_array_index] <= right_sub_array[right_sub_array_index]) {
            array[merged_array_index] = left_sub_array[left_sub_array_index];
            ++left_sub_array_index;
        } else {
            array[merged_array_index] = right_sub_array[right_sub_array_index];
            ++right_sub_array_index;
        }

        ++merged_array_index;
    }

    while (left_sub_array_index < left_sub_array_size) {
        array[merged_array_index] = left_sub_array[left_sub_array_index];
        ++left_sub_array_index;
        ++merged_array_index;
    }

    while (right_sub_array_index < right_sub_array_size) {
        array[merged_array_index] = right_sub_array[right_sub_array_index];
        ++right_sub_array_index;
        ++merged_array_index;
    }

    delete[] left_sub_array;
    delete[] right_sub_array;
}

void mergeSort(int array[], int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);

    merge(array, begin, mid, end);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int fixed = high;

    for (int i = high; i > low; --i) {
        if (arr[i] > pivot) {
            std::swap(arr[i], arr[fixed]);
            --fixed;
        }
    }

    std::swap(arr[low], arr[fixed]);

    return fixed;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

void heapify(int arr[], int i, int n) {
    int largest_child, left_child, right_child;
    while (true) {
        largest_child = i;
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;

        if (left_child < n && arr[left_child] > arr[largest_child]) {
            largest_child = left_child;
        }
        if (right_child < n && arr[right_child] > arr[largest_child]) {
            largest_child = right_child;
        }
        if (largest_child == i) {
            break;
        }

        std::swap(arr[i], arr[largest_child]);
        i = largest_child;
    }
}

int getMaxFromHeap(int arr[], int n) {
    int max = arr[0];
    arr[0] = arr[n - 1];
    return max;
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 0; --i) {
        heapify(arr, i, n);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; --i) {
        arr[i] = getMaxFromHeap(arr, n--);
        heapify(arr, 0, n);
    }
}

void shellSortTsiurSequence(int arr[], int n) {
    int tsiur_array[9] {1, 4, 10, 23, 57, 132, 301, 701, 1750 };
    int step, i, j, k;

    for (k = 8; k >= 0; --k) {
        step = tsiur_array[k];
        for (i = step; i < n; ++i) {
            for(j = i - step; j >= 0; j -= step) {
                if (arr[j + step] >= arr[j]) {
                    break;
                }
                std::swap(arr[j], arr[j + step]);
            }
        }
    }
}

void shellSortShellSequence(int arr[], int n) {
    int step, i, j;

    for (step = n / 2; step != 0; step /= 2) {
        for (i = step; i < n; ++i) {
            for(j = i - step; j >= 0; j -= step) {
                if (arr[j + step] >= arr[j]) {
                    break;
                }
                std::swap(arr[j], arr[j + step]);
            }
        }
    }
}
