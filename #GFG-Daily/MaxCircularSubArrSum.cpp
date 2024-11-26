// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

// Date-> 26/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int maxi=INT_MIN, mini=INT_MAX, maxSum=0, minSum=0, totalSum=0;
        
        for(int i=0; i<n; i++){
            totalSum += arr[i];
            maxSum = max(arr[i], maxSum+arr[i]);
            maxi   = max(maxi,maxSum);
            minSum = min(arr[i], minSum+arr[i]);
            mini   = min(mini, minSum);
        }
        
        return max(maxi, totalSum-mini);

    }
};