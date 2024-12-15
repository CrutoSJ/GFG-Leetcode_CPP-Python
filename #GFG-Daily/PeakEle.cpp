// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/peak-element/1

// Date-> 15/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int low=0, high=n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])){
                return mid;
            }
            
            if(mid > 0 && arr[mid-1] > arr[mid]){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
    }
};