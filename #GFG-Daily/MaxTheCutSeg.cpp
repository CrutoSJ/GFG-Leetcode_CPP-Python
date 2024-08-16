// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/cutted-segments1642/1

// Date-> 16/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int solve(int n, int x, int y, int z, vector<int> &dp){
        if( n == 0){
            return 0;
        }
        
        if( n<0 ){
            return INT_MIN;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int cutX = solve(n-x,x,y,z,dp) + 1;
        int cutY = solve(n-y,x,y,z,dp) + 1;
        int cutZ = solve(n-z,x,y,z,dp) + 1;
        
        dp[n] = max({cutX, cutY, cutZ});
        
        return dp[n];
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        int ans = solve(n, x, y, z, dp);
        
        if(ans<0){
            return 0;
        }
        return ans;
    }
};