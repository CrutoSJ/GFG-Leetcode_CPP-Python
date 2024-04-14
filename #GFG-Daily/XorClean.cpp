// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/xoring-and-clearing/1

// You are given an array arr[] of size n. You need to do the following:

// You need to calculate the bitwise XOR of each element in the array with its corresponding index (indices start from 0).
// After step1, print the array.
// Now, set all the elements of arr[] to zero.
// Now, print arr[].

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printArr(int n, int arr[]) {
        // Your code for printing array here
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void setToZero(int n, int arr[]) {
        // Use memset to set arr to zero
        for(int i=0; i<n; i++){
            arr[i]=0;
        }
    }

    void xor1ToN(int n, int arr[]) {
        // Xor arr[i]^i
        for(int i=0; i<n; i++){
            arr[i]=arr[i]^i;
        }
    }
};