// #Question:-

// Link-> https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/?envType=daily-question&envId=2025-06-12

// Date-> 12/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[0] - nums[n-1]);

        for(int i=0; i<n-1; i++){
            res = max(res, abs(nums[i] - nums[i+1]));
        }
        return res;
    }
};