// #Question:-

// Link-> https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07

// Date-> 07/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool solve(int index, vector<int>& nums, int x, vector<vector<int>>& dp) {
    
            if (x == 0) {
                return true;
            }
    
            if (index >= nums.size()) {
                return false;
            }
    
            if (dp[index][x] != -1) {
                return dp[index][x];
            }
    
            bool take = false;
            if (x >= nums[index]) {
                take = solve(index + 1, nums, x - nums[index], dp);
            }
    
            bool not_take = solve(index + 1, nums, x, dp);
    
            return dp[index][x] = take || not_take;
        }
    
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
    
            int total_sum = accumulate(nums.begin(), nums.end(), 0);
    
            if (total_sum % 2 != 0) {
                return false;
            }
    
            int x = total_sum / 2;
    
            vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    
            return solve(0, nums, x, dp);
        }
    
    };