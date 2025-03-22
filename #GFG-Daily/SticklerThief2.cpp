// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/house-robber-ii/1

// Date-> 22/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int solve(vector<int> &arr, int idx, vector<int> &dp){
            if(idx>=n){
                return 0;
            }
            
            if(dp[idx] != -1){
                return dp[idx];
            }
            
            return dp[idx] = max((arr[idx]+solve(arr, idx+2, dp)),solve(arr,idx+1, dp));
        }
      int maxValue(vector<int>& arr) {
          n=arr.size()-1;
          vector<int>dp1(n+1,-1);
          vector<int>dp2(n+1,-1);
          vector<int> arr1(arr.begin(), arr.end()-1);
          vector<int> arr2(arr.begin()+1, arr.end());
          return max(solve(arr1, 0, dp1),solve(arr2,0, dp2));
      }
  };