// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimal-cost/1

// Date-> 28/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int k, vector<int> &arr, int i, vector<int> &dp){
        if(i == arr.size()-1){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int ans = INT_MAX; 
        
        for(int j=i+1; j<=i+k && j<arr.size(); j++){
            int cost = solve(k, arr, j, dp) + abs(arr[i] - arr[j]);
            ans = min(ans, cost);
        }
        
        return dp[i] = ans;
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        int n =arr.size();
        vector<int> dp(n, -1);
        return solve(k, arr, 0, dp);
    }
};