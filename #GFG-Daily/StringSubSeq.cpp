// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

// Date - 30/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9+7;

    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = (solve(s1, s2, i-1, j-1,dp)%MOD + solve(s1,s2, i-1, j, dp)%MOD)%MOD;
        } else{
            return dp[i][j] = solve(s1,s2,i-1,j,dp)%MOD;
        }
    }

public:
    int countWays(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(m>n) return 0;
        
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(s1,s2,n-1,m-1,dp);
    }
};