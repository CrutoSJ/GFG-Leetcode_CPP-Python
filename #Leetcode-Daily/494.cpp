// #Question:-

// Link -> https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26

// Date-> 26/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));

        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        for (int index = 1; index < nums.size(); index++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[index - 1][sum + totalSum] > 0) {
                    dp[index][sum + nums[index] + totalSum] += dp[index - 1][sum + totalSum];
                    dp[index][sum - nums[index] + totalSum] += dp[index - 1][sum + totalSum];
                }
            }
        }
        return abs(target) > totalSum ? 0 : dp[nums.size() - 1][target + totalSum];
    }
};