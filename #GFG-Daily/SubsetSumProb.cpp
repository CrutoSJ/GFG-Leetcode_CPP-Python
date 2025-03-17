// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Date-> 17/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int dp[10001][201];
      bool solve(vector<int> &arr, int sum, int n){
          if(sum==0){
              return true;
          }
          
          if(n<0 || sum<0){
              return false; 
          }
          
          if(dp[sum][n] != -1){
              return dp[sum][n];
          }
          
          return dp[sum][n] = solve(arr,sum-arr[n],n-1)||solve(arr,sum,n-1);
      }
      bool isSubsetSum(vector<int>& arr, int sum) {
          memset(dp, -1, sizeof(dp));
          return solve(arr,sum,arr.size()-1);
          
      }
  };