// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Date-> 06/09/24 & 24/11/24

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        long long maxCnt = INT_MIN;
        long long maxSum = 0;
        
        for(int i=0; i<arr.size(); i++){
            maxSum += arr[i];
            
            if(maxCnt<maxSum){
                maxCnt = maxSum;
            }
            
            if(maxSum<0){
                maxSum = 0;
            }
        }
        
        return maxCnt;
    }
};