// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

// Date -> 12/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int dp[100001]; 
      int solve(vector<int> &cost, int n){
          if(n<0){
              return 0;
          }
          
          
          if(n==0){
              return cost[0];
          }
          
          if(n==1){
              return cost[1];
          }
          
          if(dp[n] != -1){
              return dp[n];
          }
          
          int sum = cost[n]+min(solve(cost,n-1),solve(cost,n-2));
          return dp[n] = sum;
      }
      int minCostClimbingStairs(vector<int>& cost) {
          int n=cost.size();
          memset(dp, -1, sizeof(dp));
          return min(solve(cost, n-1),solve(cost, n-2));
      }
  };