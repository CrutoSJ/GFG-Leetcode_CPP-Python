// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

// Date-> 20/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int dp[100001][3][2];
      int solve(vector<int> &prices, int k, int idx, bool canBuy){
          if(idx>=n || k==0){
              return 0;
          }
          
          int take=0,noTake=0;
          
          if(dp[idx][k][canBuy] != -1){
              return dp[idx][k][canBuy];
          }
          
          if(canBuy){//buy
              take=-prices[idx]+solve(prices,k,idx+1,false);
              noTake=solve(prices, k, idx+1, true);
          } else{//sell
              take=prices[idx]+solve(prices,k-1,idx+1, true);
              noTake=solve(prices, k, idx+1, false);
          }
          
          return dp[idx][k][canBuy] = max(take, noTake);
          
      }
      int maxProfit(vector<int> &prices) {
          n=prices.size();
          memset(dp, -1, sizeof(dp));
          return solve(prices, 2, 0, true);
          
      }
  };