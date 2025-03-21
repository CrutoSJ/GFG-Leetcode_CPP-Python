// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

// Date-> 21/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int dp[100001];
      int solve(vector<int> &arr, int idx){
          if(idx>=n){
              return 0;
          }
          
          if(dp[idx] != -1){
              return dp[idx];
          }
          
          return dp[idx] = max((arr[idx]+solve(arr, idx+2)),solve(arr,idx+1));
      }
      int findMaxSum(vector<int>& arr) {
          n=arr.size();
          memset(dp, -1, sizeof(dp));
          return solve(arr, 0);
          
      }
  };