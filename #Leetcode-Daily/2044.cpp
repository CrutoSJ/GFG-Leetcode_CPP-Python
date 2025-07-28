// #Question:-

// Link-> https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18

// Date-> 18/10/24 && 28/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int maxOr, vector<int> &nums, int currOr, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }

        if(dp[idx][currOr] != -1){
            return dp[idx][currOr];
        }

        int taking    = solve(idx+1, maxOr, nums, currOr|nums[idx], dp);

        int notTaking = solve(idx+1, maxOr, nums, currOr, dp);

        return dp[idx][currOr] = taking+notTaking; 
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;

        for(auto &num : nums){
            maxOr |= num;
        }

        int currOr = 0;
        vector<vector<int>> dp(n+1, vector<int>(maxOr+1, -1));

        return solve(0, maxOr, nums, currOr, dp);
    }
};