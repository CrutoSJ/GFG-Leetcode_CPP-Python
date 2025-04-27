// #Question:-

// Link-> https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/submissions/1619432043/?envType=daily-question&envId=2025-04-27

// Date-> 27/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            for (int i = 1; i < n - 1; ++i) {
                if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                    ++ans;
                }
            }
            return ans;
        }
    };