// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1

// Date-> 19/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int low=0, high = arr.size()-1, mid=0;
        
        while(low<=high){
            mid = low + (high-low)/2;
            if(arr[mid]-mid-1>=k){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return low+k;
    }
};