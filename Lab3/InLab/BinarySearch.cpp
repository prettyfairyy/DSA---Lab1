//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 01

#include <iostream>
using namespace std;

//Find the first position of target
int findFirst(int A[], int size, int target){
    int l = 0, r = size - 1;
    while (l <= r){
        int m = l + (r - l) / 2;
        if (A[m] == target) {
            if (m == 0 || A[m - 1] < target) return m;
            r = m - 1;
        }
        else if (A[m] < target) l = m - 1;    
        else r = m - 1;        
    }
    return -1;
}

//Find the last position of target
int findLast(int A[], int size, int target){
    int l = 0, r = size - 1;
    while (l <= r){
        int m = l + (r - 1) / 2;
        if (A[m] == target){
            if (m == size - 1 || A[m + 1] > target) return m;
            l = m + 1;
        }
        else if (A[m] > target) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

//Count the times a specific element appears
int count(int A[], int size, int target){
    if (findLast(A, size, target) == -1) return 0;
    return findLast(A, size, target) - findFirst(A, size, target) + 1;
}

int main(){
    int size;
    cout << "Enter number of elements in array: ";
    cin >> size;
    int *A = new int [size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) cin >> A[i];
    int target;
    cout << "Enter an element: ";
    cin >> target;
    cout << target << " appears " << count(A,size,target) << " times";
    return 0;
}