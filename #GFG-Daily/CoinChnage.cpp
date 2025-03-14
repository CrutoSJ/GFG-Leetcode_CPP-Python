// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/coin-change2448/1

// Date -> 14/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int dp[1001][1001]; 
      int solve(vector<int> &coins, int sum, int n){
          if(n<0 || sum<0){
              return 0;
          }
          
          if(sum==0){
              return 1;
          }
          
          if(dp[n][sum] != -1){
              return dp[n][sum];
          }
          
          return dp[n][sum] = solve(coins, sum-coins[n], n) + solve(coins, sum, n-1);
      }
      int count(vector<int>& coins, int sum) {
          int n=coins.size();
          memset(dp, -1, sizeof(dp));
          return solve(coins, sum, n-1);
      }
  };