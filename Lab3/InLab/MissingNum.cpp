//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 04

#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int size){
    sort(arr, arr + size);
    int l = 0, r = size;
    while (l < r){
        int mid = (l + r) / 2;
        if (arr[mid] == mid) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(){
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int* arr = new int [n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int missingNumber = binarySearch(arr, n);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}