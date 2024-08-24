// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Date-> 24/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int s;
    int dp[1001][1001];
    
    int solve(int w, vector<int> &wt, vector<int> &val, int idx){
        if(idx == s){
            return 0;
        }
        
        if(dp[w][idx] != -1){
            return dp[w][idx];
        }
        
        int pick = 0, notPick = 0;
        
        notPick = solve(w, wt, val, idx+1);
        if(w>=wt[idx]){
            pick = val[idx] + solve(w-wt[idx], wt, val, idx+1);
        }
        
        return dp[w][idx] = max(pick, notPick);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        s = wt.size();
        memset(dp, -1,sizeof(dp));
        return solve(W, wt,val, 0);
    }
};