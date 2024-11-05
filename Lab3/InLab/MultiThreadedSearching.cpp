//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 05

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int linearSearch(int arr[], int size, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target, int &comparisons) {
    comparisons = 0;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int size, int target, int &comparisons) {
    int step = sqrt(size);
    int prev = 0;
    comparisons = 0;

    while (arr[min(step, size) - 1] < target) {
        comparisons++;
        prev = step;
        step += sqrt(size);
        if (prev >= size) return -1;
    }

    for (int i = prev; i < min(step, size); i++) {
        comparisons++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int size, target;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter elements of array (sorted for binary and jump search): ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    cout << "Enter the target element: ";
    cin >> target;

    int comparisons;
    clock_t start, end;

    // Linear Search
    start = clock();
    int linearResult = linearSearch(arr, size, target, comparisons);
    end = clock();
    cout << "Linear Search - Index: " << linearResult << ", Comparisons: " << comparisons
         << ", Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    // Binary Search
    start = clock();
    int binaryResult = binarySearch(arr, 0, size - 1, target, comparisons);
    end = clock();
    cout << "Binary Search - Index: " << binaryResult << ", Comparisons: " << comparisons
         << ", Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    // Jump Search
    start = clock();
    int jumpResult = jumpSearch(arr, size, target, comparisons);
    end = clock();
    cout << "Jump Search - Index: " << jumpResult << ", Comparisons: " << comparisons
         << ", Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr;
    return 0;
}
