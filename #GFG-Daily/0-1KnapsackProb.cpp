// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Date -> 13/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int dp[1001][1001];
      int solve(int W, vector<int> &val, vector<pair<int,int>> &wt, int n){
          if(W<0 || n<0 || W<wt[n].first){
              return 0;
          }
          
          if(dp[W][n] != -1){
              return dp[W][n];
          }
          
          int take   = val[wt[n].second]+solve(W-wt[n].first, val, wt, n-1);
          int noTake = solve(W, val, wt, n-1);
          
          return dp[W][n] = max(take, noTake);
          
      }
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n=val.size();
          memset(dp, -1, sizeof(dp));
          vector<pair<int,int>> newWt;
          for(int i=0; i<n; i++){
              newWt.push_back({wt[i],i});
          }
          sort(newWt.begin(), newWt.end(), greater<pair<int,int>>());
          return solve(W,val,newWt, n-1);
      }
  };