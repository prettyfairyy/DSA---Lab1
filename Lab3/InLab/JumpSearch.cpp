//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 02

#include <iostream>
#include <math.h>
using namespace std;

int jumpSearch(int arr[], int size, int item){
    int i = 0;
    int m = sqrt(size);
    while (arr[m] <= item && m < size){
        i = m;
        m += sqrt(size);
        if (m > size - 1) return -1;
    }
    for (int j = i; j < m; j++)
        if (arr[j] == item) return j;
    return -1;
}

int main(){
    int size;
    cout << "Enter number of elements in array: ";
    cin >> size;
    int *arr = new int [size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    int target;
    cout << "Enter an element: ";
    cin >> target;
    int result = jumpSearch(arr, size, target);
    if (result == -1) cout << "Not found";
    else cout << "The index of " << target << " is " << result;
    delete[] arr;
    return 0;
}