// #Question:-

// Link-> https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25

// Date-> 25/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumsSet;
        for (int num : nums) {
            if (num > 0) {
                positiveNumsSet.emplace(num);
            }
        }
        if (positiveNumsSet.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};