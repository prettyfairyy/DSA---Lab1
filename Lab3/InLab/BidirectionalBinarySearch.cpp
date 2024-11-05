//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 06

#include <iostream>
using namespace std;

int bidirectionalBinarySearch(int arr[], int size, int target, int &comparisons) {
    int left = 0, right = size - 1;
    comparisons = 0;

    while (left <= right) {
        comparisons += 2;  // Two comparisons (left and right)
        int midLeft = left + (right - left) / 2;
        int midRight = right - (right - left) / 2;

        if (arr[midLeft] == target) return midLeft;
        if (arr[midRight] == target) return midRight;

        if (arr[midLeft] < target) left = midLeft + 1;
        else right = midLeft - 1;

        if (arr[midRight] > target) right = midRight - 1;
        else left = midRight + 1;
    }
    return -1;
}

int main() {
    int size, target;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter elements of the sorted array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    cout << "Enter the target element: ";
    cin >> target;

    int comparisons;
    int result = bidirectionalBinarySearch(arr, size, target, comparisons);

    cout << "Bidirectional Binary Search - Index: " << result << ", Comparisons: " << comparisons << endl;

    delete[] arr;
    return 0;
}
