// #Question:-

// Link-> https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03

// Date-> 03/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftSum = 0, rightSum = 0;

        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }
        return count;
    }
};