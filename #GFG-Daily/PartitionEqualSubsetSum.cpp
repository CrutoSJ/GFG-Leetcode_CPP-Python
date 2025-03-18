// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Date-> 17/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int dp[101][10001];
      bool solve(vector<int> &arr, int n, int sum, int curSum){
          
          if(sum==curSum){
              return true;
          }
          
          if(n<0 || sum<0){
              return false;
          }
          
          if(dp[n][sum] != -1){
              return dp[n][sum];
          }
          
          return dp[n][sum] = solve(arr,n-1, sum-arr[n], curSum+arr[n])||solve(arr,n-1,sum,curSum);
      }
      bool equalPartition(vector<int>& arr) {
          int sum = accumulate(arr.begin(), arr.end(), 0);
          memset(dp, -1, sizeof(dp));
          return solve(arr,arr.size()-1, sum, 0);
      }
  };