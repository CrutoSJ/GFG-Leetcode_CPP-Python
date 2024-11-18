// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

// Date-> 18/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if(d>=n){
            d = d%n;    
        }
        
        int i=0, j=d-1;
        while(i<=j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
        
        i=n-(n-d), j=n-1;
        while(i<=j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
        
        i=0, j=n-1;
        while(i<=j){
            swap(arr[i], arr[j]);
            i++,j--;
        }
    }
};