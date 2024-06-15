// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long solve(int i, int j, int n, vector<vector<vector<long long>>> &dp){
        if(i>3 || j>2 || i<0 || j<0) return 0;
        if(i==3 && (j==0 || j==2)) return 0;
        if(n==1) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        n--;
        return dp[i][j][n+1] = solve(i-1,j,n,dp)+solve(i,j-1,n,dp)+solve(i+1,j,n,dp)+solve(i,j+1,n,dp)+solve(i,j,n,dp);
    }
public:
    long long getCount(int n) {
        long long ans = 0;
        vector<vector<vector<long long>>>dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        for(int i=0; i<4; i++){
            for(int j=0;j<3; j++){
                if(i==3 && (j==0 || j==2)) continue;
                ans+=solve(i,j,n,dp);
            }
        }
        return ans;
    }
};