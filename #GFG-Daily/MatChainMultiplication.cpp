// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Date-> 24/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int dp[101][101];
      int solve(vector<int> &arr, int i, int j){
          if(i==j){
              return 0;
          }
          
          if(dp[i][j] != -1){
              return dp[i][j];
          }
          
          int mini=INT_MAX;
          
          for(int k=i; k<=j-1; k++){
              int ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
              mini = min(mini, ans);
          }
          return dp[i][j] = mini;
      }
      int matrixMultiplication(vector<int> &arr) {
          n=arr.size();
          memset(dp, -1, sizeof(dp));
          return solve(arr, 1, n-1);
      }
  };