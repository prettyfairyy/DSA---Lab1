#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

// Standard Insertion Sort for small subarrays
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort
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

// Hybrid Quick-Insertion Sort
void hybridQuickSort(int arr[], int low, int high) {
    // Threshold for switching to Insertion Sort
    const int threshold = 10;

    if (low < high) {
        // If the size of the subarray is less than or equal to threshold, use Insertion Sort
        if (high - low + 1 <= threshold) {
            insertionSort(arr, low, high);
        } else {
            // Use Quick Sort for larger subarrays
            int pi = partition(arr, low, high);
            hybridQuickSort(arr, low, pi - 1);
            hybridQuickSort(arr, pi + 1, high);
        }
    }
}

// Standard Quick Sort for comparison
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display an array (useful for debugging)
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Benchmark function to measure sorting performance
template <typename Func>
void benchmark(Func sortFunc, int arr[], int size, const string& sortName) {
    int* tempArr = new int[size];
    copy(arr, arr + size, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << sortName << " time: " << duration.count() << " seconds" << endl;

    delete[] tempArr;
}

int main() {
    const int size = 1000;
    int arr[size];

    // Populate the array with random numbers
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }

    // Display unsorted array (optional)
    cout << "Unsorted array (first 10 elements): ";
    displayArray(arr, 10); // Display first 10 elements for brevity

    // Benchmark Standard Quick Sort
    benchmark(quickSort, arr, size, "Standard Quick Sort");

    // Benchmark Hybrid Quick-Insertion Sort
    benchmark(hybridQuickSort, arr, size, "Hybrid Quick-Insertion Sort");

    return 0;
}
