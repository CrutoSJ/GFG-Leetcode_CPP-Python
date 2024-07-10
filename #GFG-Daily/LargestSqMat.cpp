// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// Date-> 10/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        //base case:-
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        //recursive call:-
        int right = solve(mat, i, j+1, maxi, dp);
        int diagonal = solve(mat, i+1, j+1, maxi, dp);
        int down = solve(mat, i+1, j, maxi, dp);
        
        if(mat[i][j]==1){
            dp[i][j] = 1+min(right, min(diagonal,down));
            maxi = max(dp[i][j],maxi);
            return dp[i][j];
        } else{
            return dp[i][j]=0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int maxi = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(mat, 0, 0, maxi, dp);
        return maxi;
    }
};
