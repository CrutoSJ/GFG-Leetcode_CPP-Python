// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

// Date-> 27/11/24 && 22/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        int i = 0;
        while(i<n){
            if(arr[i]>0 && arr[i]<=n && arr[i] != arr[arr[i]-1]){
                swap(arr[i], arr[arr[i]-1]);
            } else{
                i++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};