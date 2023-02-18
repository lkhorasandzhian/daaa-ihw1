#include <algorithm>

unsigned long long global_counter = 0;

void selectionSortCounter(int arr[], int n) {
    int i, j;
    int min_index;
    global_counter += 3;

    global_counter += 3;
    for (i = 0; i < n - 1; ++i) {
        global_counter += 4;
        min_index = i;
        global_counter += 1;

        global_counter += 3;
        for (j = i + 1; j < n; ++j) {
            global_counter += 3;
            global_counter += 3;
            if (arr[j] < arr[min_index]) {
                min_index = j;
                global_counter += 1;
            }
        }

        global_counter += 1;
        if (min_index != i) {
            std::swap(arr[min_index], arr[i]);
            global_counter += 5;
        }
    }
}

void bubbleSortCounter(int arr[], int n) {
    int i, j;
    global_counter += 2;

    global_counter += 3;
    for (i = 0; i < n - 1; ++i) {
        global_counter += 4;
        global_counter += 3;
        for (j = 0; j < n - 1; ++j) {
            global_counter += 4;
            global_counter += 4;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                global_counter += 6;
            }
        }
    }
}

void bubbleSortIversonFirstCounter(int arr[], int n) {
    int i = 0, j;
    bool was_swapped;
    global_counter += 4;

    do {
        was_swapped = false;
        global_counter += 1;
        global_counter += 3;
        for (j = 0; j < n - 1; ++j) {
            global_counter += 4;
            global_counter += 4;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                global_counter += 6;
                was_swapped = true;
                global_counter += 1;
            }
        }
        ++i;
        global_counter += 2;
        global_counter += 1;
    } while (was_swapped);
}

void bubbleIversonFirstAndSecondCounter(int arr[], int n) {
    int i = 0, j;
    bool was_swapped;
    global_counter += 4;

    do {
        was_swapped = false;
        global_counter += 1;
        global_counter += 4;
        for (j = 0; j < n - i - 1; ++j) {
            global_counter += 5;
            global_counter += 4;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                global_counter += 6;
                was_swapped = true;
                global_counter += 1;
            }
        }
        ++i;
        global_counter += 2;
        global_counter += 1;
    } while (was_swapped);
}

void insertionSortCounter(int arr[], int n) {
    int i, j;
    int key;
    global_counter += 3;

    global_counter += 2;
    for (i = 1; i < n; ++i) {
        global_counter += 3;
        key = arr[i];
        global_counter += 2;
        j = i - 1;
        global_counter += 2;

        global_counter += 4;
        while (j >= 0 && arr[j] > key) {
            global_counter += 4;
            arr[j + 1] = arr[j];
            global_counter += 4;
            --j;
            global_counter += 2;
        }

        arr[j + 1] = key;
        global_counter += 3;
    }
}

int binarySearchCounter(const int arr[], int key, int left, int right) {
    int middle;
    global_counter += 1;

    global_counter += 2;
    while (right - left > 1) {
        global_counter += 2;
        middle = left + (right - left) / 2;
        global_counter += 4;

        global_counter += 2;
        if (key > arr[middle]) {
            left = middle;
            global_counter += 1;
        } else if (key < arr[middle]) {
            global_counter += 2;
            right = middle;
            global_counter += 1;
        } else {
            global_counter += 2;
            global_counter += 2;
            return middle + 1;
        }
    }

    global_counter += key > arr[left] ? 4 : 3;
    return key > arr[left] ? left + 1 : left;
}

void binaryInsertionSortCounter(int arr[], int n) {
    int i, j;
    int position, current;
    global_counter += 4;

    global_counter += 2;
    for (i = 1; i < n; ++i) {
        global_counter += 3;
        j = i - 1;
        global_counter += 2;
        current = arr[i];
        global_counter += 2;

        position = binarySearchCounter(arr, current, 0, j + 1);
        global_counter += 2;

        global_counter += 1;
        while (j >= position) {
            global_counter += 1;
            arr[j + 1] = arr[j];
            global_counter += 4;
            --j;
            global_counter += 2;
        }

        arr[j + 1] = current;
        global_counter += 3;
    }
}

int getMinCounter(const int arr[], int n) {
    int min = INT_MAX;
    global_counter += 2;

    global_counter += 3;
    for (int i = 0; i < n; ++i) {
        global_counter += 3;
        global_counter += 2;
        if (arr[i] < min) {
            min = arr[i];
            global_counter += 2;
        }
    }

    global_counter += 1;
    return min;
}

int getMaxCounter(const int arr[], int n) {
    int max = INT_MIN;
    global_counter += 2;

    global_counter += 3;
    for (int i = 0; i < n; ++i) {
        global_counter += 3;
        global_counter += 2;
        if (arr[i] > max) {
            max = arr[i];
            global_counter += 2;
        }
    }

    global_counter += 1;
    return max;
}

void stableCountingSortCounter(int arr[], int n) {
    int lower_bound = getMinCounter(arr, n), upper_bound = getMaxCounter(arr, n);
    global_counter += 4;
    int sorted_arr[n];
    global_counter += 2;
    const int k = upper_bound - lower_bound + 1;
    global_counter += 3;
    int counter[k];
    global_counter += 2;
    int i;
    global_counter += 1;

    global_counter += 2;
    for (i = 0; i < k; ++i) {
        global_counter += 3;
        counter[i] = 0;
        global_counter += 2;
    }

    global_counter += 2;
    for (i = 0; i < n; ++i) {
        global_counter += 2;
        ++counter[arr[i] - lower_bound];
        global_counter += 5;
    }

    global_counter += 2;
    for (i = 1; i < k; ++i) {
        global_counter += 3;
        counter[i] += counter[i - 1];
        global_counter += 6;
    }

    global_counter += 3;
    for (i = n - 1; i >= 0; --i) {
        global_counter += 3;
        --counter[arr[i] - lower_bound];
        global_counter += 4;
        sorted_arr[counter[arr[i] - lower_bound]] = arr[i];
        global_counter += 6;
    }

    global_counter += 2;
    for (i = 0; i < n; ++i) {
        global_counter += 3;
        arr[i] = sorted_arr[i];
        global_counter += 3;
    }
}

int getSelectedDigit10Counter(int number, int position) {
    global_counter += 3;
    for (int i = 0; i < position; ++i) {
        global_counter += 3;
        number /= 10;
        global_counter += 2;
    }
    global_counter += 2;
    return number % 10;
}

void radixSort10Counter(int arr[], int n) {
    int sorted_arr[n];
    global_counter += 2;
    int counter[10];
    global_counter += 2;
    int i, j;
    global_counter += 2;

    global_counter += 2;
    for (i = 0; i < 9; ++i) {
        global_counter += 3;
        global_counter += 2;
        for (j = 0; j < 10; ++j) {
            global_counter += 3;
            counter[j] = 0;
            global_counter += 2;
        }

        global_counter += 2;
        for (j = 0; j < n; ++j) {
            global_counter += 3;
            ++counter[getSelectedDigit10Counter(arr[j], i)];
            global_counter += 3;
        }

        global_counter += 2;
        for (j = 1; j < 10; ++j) {
            global_counter += 3;
            counter[j] += counter[j - 1];
            global_counter += 6;
        }

        global_counter += 3;
        for (j = n - 1; j >= 0; --j) {
            global_counter += 3;
            --counter[getSelectedDigit10Counter(arr[j], i)];
            global_counter += 3;
            sorted_arr[counter[getSelectedDigit10Counter(arr[j], i)]] = arr[j];
            global_counter += 5;
        }

        global_counter += 2;
        for (j = 0; j < n; ++j) {
            global_counter += 3;
            arr[j] = sorted_arr[j];
            global_counter += 3;
        }
    }
}

void mergeCounter(int array[], int left, int middle, int right) {
    int left_sub_array_size = middle - left + 1;
    global_counter += 4;
    int right_sub_array_size = right - middle;
    global_counter += 3;

    int *left_sub_array = new int[left_sub_array_size];
    global_counter += left_sub_array_size + 1;
    int *right_sub_array = new int[right_sub_array_size];
    global_counter += right_sub_array_size + 1;

    int i;
    global_counter += 1;

    global_counter += 2;
    for (i = 0; i < left_sub_array_size; ++i) {
        global_counter += 3;
        left_sub_array[i] = array[left + i];
        global_counter += 4;
    }
    global_counter += 2;
    for (i = 0; i < right_sub_array_size; ++i) {
        global_counter += 3;
        right_sub_array[i] = array[middle + 1 + i];
        global_counter += 5;
    }

    int left_sub_array_index = 0, right_sub_array_index = 0;
    global_counter += 4;
    int merged_array_index = left;
    global_counter += 2;

    global_counter += 3;
    while (left_sub_array_index < left_sub_array_size && right_sub_array_index < right_sub_array_size) {
        global_counter += 3;
        if (left_sub_array[left_sub_array_index] <= right_sub_array[right_sub_array_index]) {
            array[merged_array_index] = left_sub_array[left_sub_array_index];
            global_counter += 3;
            ++left_sub_array_index;
            global_counter += 2;
        } else {
            array[merged_array_index] = right_sub_array[right_sub_array_index];
            global_counter += 3;
            ++right_sub_array_index;
            global_counter += 2;
        }

        ++merged_array_index;
        global_counter += 2;
    }

    global_counter += 1;
    while (left_sub_array_index < left_sub_array_size) {
        global_counter += 1;
        array[merged_array_index] = left_sub_array[left_sub_array_index];
        global_counter += 3;
        ++left_sub_array_index;
        global_counter += 2;
        ++merged_array_index;
        global_counter += 2;
    }

    global_counter += 1;
    while (right_sub_array_index < right_sub_array_size) {
        global_counter += 1;
        array[merged_array_index] = right_sub_array[right_sub_array_index];
        global_counter += 3;
        ++right_sub_array_index;
        global_counter += 2;
        ++merged_array_index;
        global_counter += 2;
    }

    delete[] left_sub_array;
    global_counter += left_sub_array_size;
    delete[] right_sub_array;
    global_counter += right_sub_array_size;
}

void mergeSortCounter(int array[], int begin, int end) {
    global_counter += 1;
    if (begin >= end) {
        global_counter += 1;
        return;
    }

    int mid = begin + (end - begin) / 2;
    global_counter += 5;

    mergeSortCounter(array, begin, mid);
    mergeSortCounter(array, mid + 1, end);
    global_counter += 1;

    mergeCounter(array, begin, mid, end);
}

int partitionCounter(int arr[], int low, int high) {
    int pivot = arr[low];
    global_counter += 3;
    int fixed = high;
    global_counter += 2;

    global_counter += 3;
    for (int i = high; i > low; --i) {
        global_counter += 3;
        global_counter += 2;
        if (arr[i] > pivot) {
            std::swap(arr[i], arr[fixed]);
            global_counter += 5;
            --fixed;
            global_counter += 2;
        }
    }

    std::swap(arr[low], arr[fixed]);
    global_counter += 5;

    global_counter += 1;
    return fixed;
}

void quickSortCounter(int arr[], int low, int high) {
    global_counter += 1;
    if (low < high) {
        int pivot_index = partitionCounter(arr, low, high);
        global_counter += 2;

        quickSortCounter(arr, low, pivot_index - 1);
        global_counter += 1;
        quickSortCounter(arr, pivot_index + 1, high);
        global_counter += 1;
    }
}

void heapifyCounter(int arr[], int i, int n) {
    int largest_child, left_child, right_child;
    global_counter += 3;
    while (true) {
        largest_child = i;
        global_counter += 1;
        left_child = 2 * i + 1;
        global_counter += 3;
        right_child = 2 * i + 2;
        global_counter += 3;

        global_counter += 5;
        if (left_child < n && arr[left_child] > arr[largest_child]) {
            largest_child = left_child;
            global_counter += 1;
        }
        global_counter += 5;
        if (right_child < n && arr[right_child] > arr[largest_child]) {
            largest_child = right_child;
            global_counter += 1;
        }
        global_counter += 1;
        if (largest_child == i) {
            global_counter += 1;
            break;
        }

        std::swap(arr[i], arr[largest_child]);
        global_counter += 5;
        i = largest_child;
        global_counter += 1;
    }
}

int getMaxFromHeapCounter(int arr[], int n) {
    int max = arr[0];
    global_counter += 3;
    arr[0] = arr[n - 1];
    global_counter += 4;
    global_counter += 1;
    return max;
}

void buildHeapCounter(int arr[], int n) {
    global_counter += 3;
    for (int i = n / 2; i >= 0; --i) {
        global_counter += 3;
        heapifyCounter(arr, i, n);
    }
}

void heapSortCounter(int arr[], int n) {
    buildHeapCounter(arr, n);

    global_counter += 4;
    for (int i = n - 1; i >= 0; --i) {
        global_counter += 3;
        arr[i] = getMaxFromHeapCounter(arr, n--);
        global_counter += 4;
        heapifyCounter(arr, 0, n);
    }
}

void shellSortTsiurSequenceCounter(int arr[], int n) {
    int tsiur_array[9] { 1, 4, 10, 23, 57, 132, 301, 701, 1750 };
    global_counter += 10;
    int step, i, j, k;
    global_counter += 4;

    global_counter += 2;
    for (k = 8; k >= 0; --k) {
        global_counter += 3;
        step = tsiur_array[k];
        global_counter += 2;
        global_counter += 2;
        for (i = step; i < n; ++i) {
            global_counter += 3;
            global_counter += 3;
            for(j = i - step; j >= 0; j -= step) {
                global_counter += 3;
                global_counter += 4;
                if (arr[j + step] >= arr[j]) {
                    global_counter += 1;
                    break;
                }
                std::swap(arr[j], arr[j + step]);
                global_counter += 6;
            }
        }
    }
}

void shellSortShellSequenceCounter(int arr[], int n) {
    int step, i, j;
    global_counter += 3;

    global_counter += 3;
    for (step = n / 2; step != 0; step /= 2) {
        global_counter += 3;
        global_counter += 2;
        for (i = step; i < n; ++i) {
            global_counter += 3;
            global_counter += 3;
            for(j = i - step; j >= 0; j -= step) {
                global_counter += 3;
                global_counter += 4;
                if (arr[j + step] >= arr[j]) {
                    global_counter += 1;
                    break;
                }
                std::swap(arr[j], arr[j + step]);
                global_counter += 6;
            }
        }
    }
}
