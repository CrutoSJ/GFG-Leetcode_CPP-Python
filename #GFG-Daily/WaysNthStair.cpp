// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

// Date -> 11/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int dp[45];
      int solve(int n){
          if(n<0){
              return 0;
          }
          
          if(n==0 || n==1){
              return 1;
          }
          
          if(dp[n] != -1){
              return dp[n];
          }
          
          int one = solve(n-1);
          int two = solve(n-2);
          
          return dp[n] = one+two;
          
      }
      int countWays(int n) {
          memset(dp,-1,sizeof(dp));
          return solve(n);
          
      }
  };