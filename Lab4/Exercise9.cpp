#include <iostream>
#include <cmath>      // For sqrt
#include <chrono>     // For measuring time

using namespace std;

// Structure to represent a 2D point
struct Point {
    int x, y;

    // Function to calculate the distance from the origin (0, 0)
    double distanceFromOrigin() const {
        return sqrt(x * x + y * y);
    }
};

// Function to display an array of Points
void displayPoints(Point arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
    }
    cout << endl;
}

// Bubble Sort for Points
void bubbleSortPoints(Point arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].distanceFromOrigin() > arr[j + 1].distanceFromOrigin()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort for Points
void selectionSortPoints(Point arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j].distanceFromOrigin() < arr[minIndex].distanceFromOrigin()) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort for Points
void insertionSortPoints(Point arr[], int size) {
    for (int i = 1; i < size; ++i) {
        Point key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].distanceFromOrigin() > key.distanceFromOrigin()) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort on Points
int partitionPoints(Point arr[], int low, int high) {
    double pivot = arr[high].distanceFromOrigin();
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j].distanceFromOrigin() <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort for Points
void quickSortPoints(Point arr[], int low, int high) {
    if (low < high) {
        int pi = partitionPoints(arr, low, high);
        quickSortPoints(arr, low, pi - 1);
        quickSortPoints(arr, pi + 1, high);
    }
}

// Helper function to measure and display the execution time of a sorting function
template <typename SortFunc>
void benchmark(SortFunc sortFunc, Point arr[], int size, const string& sortName) {
    Point tempArr[size];
    copy(arr, arr + size, tempArr);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds" << endl;

    cout << "Sorted points by " << sortName << ": ";
    displayPoints(tempArr, size);
    cout << endl;
}

int main() {
    const int pointSize = 10;
    Point points[pointSize] = {{3, 4}, {1, 1}, {0, 0}, {5, 12}, {9, 10}, {8, 15}, {2, 3}, {7, 24}, {6, 8}, {4, 9}};

    cout << "Original points:" << endl;
    displayPoints(points, pointSize);

    // Benchmark each sorting algorithm for sorting points by distance from the origin
    cout << "\nSorting Points by distance from origin:\n";
    benchmark(bubbleSortPoints, points, pointSize, "Bubble Sort");
    benchmark(selectionSortPoints, points, pointSize, "Selection Sort");
    benchmark(insertionSortPoints, points, pointSize, "Insertion Sort");

    // Quick Sort requires different parameters
    Point tempArr[pointSize];
    copy(points, points + pointSize, tempArr);
    auto start = chrono::high_resolution_clock::now();
    quickSortPoints(tempArr, 0, pointSize - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickSortDuration = end - start;
    cout << "Quick Sort took " << quickSortDuration.count() << " seconds" << endl;
    cout << "Sorted points by Quick Sort: ";
    displayPoints(tempArr, pointSize);

    return 0;
}
