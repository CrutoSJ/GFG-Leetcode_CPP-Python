// #Question:-

// Link-> https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04

// Date-> 04/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=0;

        for(int stIdx=0; stIdx<nums.size(); stIdx++){
            int currSubSum=nums[stIdx];

            for(int endIdx=stIdx+1; endIdx<nums.size() && nums[endIdx] > nums[endIdx-1]; endIdx++){
                currSubSum += nums[endIdx];
            }
            maxSum = max(maxSum, currSubSum);
        }
        return maxSum;
    }
};