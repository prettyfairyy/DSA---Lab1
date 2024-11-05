//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 07

#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k) return arr[pivotIndex];
        else if (pivotIndex > k) return quickSelect(arr, left, pivotIndex - 1, k);
        else return quickSelect(arr, pivotIndex + 1, right, k);
    }
    return -1;
}

int main() {
    int size, k;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    cout << "Enter the value of k (1 <= k <= " << size << "): ";
    cin >> k;

    int kthSmallest = quickSelect(arr, 0, size - 1, k - 1);
    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;

    delete[] arr;
    return 0;
}
