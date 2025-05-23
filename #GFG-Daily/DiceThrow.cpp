// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

// Date-> 23/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int m, int n, int x, vector<vector<vector<int>>> &dp){
        if(x<0){
            return 0;
        }
        if(n==0){
            return x==0?1:0;
        }
        if(dp[m][n][x] != -1){
            return dp[m][n][x];
        }
        int cnt = 0;
        for(int i=1; i<=m; i++){
            cnt += solve(m, n-1, x-i, dp);
        }
        
        return dp[m][n][x] = cnt;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51,vector<int>(51,-1)));
        return solve(m, n, x, dp);
    }
};