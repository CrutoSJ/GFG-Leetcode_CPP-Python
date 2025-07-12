// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

// Date-> 12/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[501][501];
    int solve(int i,int j,int n,int m,vector<vector<int>>& mat){
        if(i>=n || i<0 || j>=m || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=mat[i][j]+solve(i,j+1,n,m,mat);
        int up=mat[i][j]+solve(i-1,j+1,n,m,mat);
        int down=mat[i][j]+solve(i+1,j+1,n,m,mat);
        return dp[i][j]=max({right,up,down});
        
    }
    int maxGold(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,n,m,mat));
        }
        return ans;
    }
};