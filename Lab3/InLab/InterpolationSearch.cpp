//StudentID: 22520836
//Name: Ngo Thi Hong Ly
//Sesson 01 - Exercise 03

#include <iostream>
using namespace std;

int interpolationSearch(string arr[], int size, string x){
    int lo = 0, hi = (size-1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]){
        if (lo == hi){
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + ((x.compare(arr[lo]) * (hi - lo)) / (arr[hi].compare(arr[lo])));        
        if (pos < lo || pos > hi) return -1;
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) lo = pos + 1;
        else hi = pos - 1;
    }    
    return -1;
}

int main(){
    int size;
    cout << "Enter number of elements in array: ";
    cin >> size;
    string *arr = new string [size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    string target;
    cout << "Enter an element: ";
    cin >> target;
    cout << "The index of" << target << " is " << interpolationSearch(arr,size,target);
    delete[] arr;
    return 0;
}