// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/number-of-coins1824/1

// Date -> 15/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int minCoins(vector<int> &coins, int sum) {
          int n = coins.size();
          vector<int> dp(sum + 1, INT_MAX);
          
          dp[0] = 0;
          
          for (int i = 1; i <= sum; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                      dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                  }
              }
          }
          
          return dp[sum] == INT_MAX ? -1 : dp[sum];
      }
  };