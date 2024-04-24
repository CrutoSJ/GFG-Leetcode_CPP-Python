// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

// You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move 
// either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return solve(x,y,dp);
    }
    int solve(int x,int y,vector<vector<int>>&dp){
        if(x==0 && y==0){
            return 1;
        }
        if(x<0 || y<0){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        dp[x][y]=(solve(x-1,y,dp)+solve(x,y-1,dp))%1000000007;
        return dp[x][y];
    }
};