// #Question:-

// Link-> https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/?envType=daily-question&envId=2025-06-16

// Date-> 16/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int preMin = nums[0];
        int res = -1;

        for(int i=0; i<n; i++){
            if(nums[i] > preMin){
                res = max(res, (nums[i] - preMin));
            } else{
                preMin = nums[i];
            }
        }

        return res;
    }
};