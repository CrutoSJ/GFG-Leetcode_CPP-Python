// #Question:-

// Link-> https://leetcode.com/problems/largest-divisible-subset/submissions/1598503173/?envType=daily-question&envId=2025-04-06

// Date-> 06/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int maxLen = 1, endIdx = 0, n = nums.size();
            vector<pair<int, int>> dp(n, {1, -1});
            for(int end = 0; end < n; end++) {
                for(int start = 0; start < end; start++) {
                    int numEnd = nums[end], numStart = nums[start];
                    int currLen = dp[end].first;
                    int newLen = (numEnd % numStart) == 0 ? dp[start].first + 1 : 0;
                    if(newLen > currLen) dp[end] = {newLen, start};
                    if(newLen > maxLen) {
                        maxLen = newLen;
                        endIdx = end;
                    }
                }
            }
            vector<int> res;
            while(endIdx != -1) {
                res.push_back(nums[endIdx]);
                endIdx = dp[endIdx].second;
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };