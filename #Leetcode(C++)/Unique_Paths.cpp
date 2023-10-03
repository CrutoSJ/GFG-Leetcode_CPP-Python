// #Questions:-

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// #Solutions:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int helper(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i<=0 || j<=0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = helper(i-1,j,m,n,dp) + helper(i,j-1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,m,n,dp);
    }
};

int main() {
    int t;
    cout<< "Enter no. of test cases: ";
    cin >> t;

    Solution solution;

    while(t--){
        int m, n;
        cout << "Enter m and n for the grid: ";
        cin >> m >> n;

        int result = solution.uniquePaths(m, n);
        cout << "Unique paths for " << m << " x " << n << " grid: " << result << endl;
    }

    return 0;

}