// #Question:-

// Given an array arr of n positive integers. The task is to swap every ith element of the array with (i+2)th element.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void swapElements(int arr[], int n){
        for(int i=0; i+2<n; i++){
            swap(arr[i],arr[i+2]);
        }
    }
};