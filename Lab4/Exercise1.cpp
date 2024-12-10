#include <iostream>
#include <chrono>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

// Bubble Sort for integers
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort for integers
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort for integers
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort for integers
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function for benchmarking sorting functions
template <typename SortFunc>
void benchmark(SortFunc sortFunc, int arr[], int size, const string& sortName) {
    int tempArr[size];
    copy(arr, arr + size, tempArr);
    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " time: " << duration.count() << " seconds" << endl;
}

int main() {
    const int size = 1000;
    int arr[size];
    srand(time(0));

    // Generate 1,000 random integers between 0 and 9999
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }

    cout << "Sorting 1K integers with different algorithms:" << endl;

    // Benchmark each sorting algorithm
    benchmark(bubbleSort, arr, size, "Bubble Sort");
    benchmark(selectionSort, arr, size, "Selection Sort");
    benchmark(insertionSort, arr, size, "Insertion Sort");

    // Quick Sort requires different parameters
    auto start = chrono::high_resolution_clock::now();
    int tempArr[size];
    copy(arr, arr + size, tempArr);
    quickSort(tempArr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickSortDuration = end - start;
    cout << "Quick Sort time: " << quickSortDuration.count() << " seconds" << endl;

    return 0;
}
