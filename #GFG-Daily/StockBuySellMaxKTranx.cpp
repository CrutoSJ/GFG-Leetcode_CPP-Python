// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-profit4657/1

// Date-> 19/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int dp[201][1001][2];
      int solve(vector<int> &prices, int k, int idx, bool canBuy){
          if(k<=0 || idx>=n){
              return 0;
          }
          
          if(dp[k][idx][canBuy] != -1){
              return dp[k][idx][canBuy];
          }
          
          int take=0,noTake=0;
          
          if(canBuy){//buy
              take   =-prices[idx]+solve(prices,k,idx+1,false);
              noTake =solve(prices,k,idx+1,true);
          } else{//sell
              take   = prices[idx]+solve(prices,k-1,idx+1,true);
              noTake = solve(prices,k,idx+1,false);
          }
          
          return dp[k][idx][canBuy] = max(take,noTake);
      }
      int maxProfit(vector<int>& prices, int k) {
          n = prices.size();
          memset(dp, -1, sizeof(dp));
          return solve(prices, k, 0, true);
          
      }
  };