// #Question:-

// Link-> https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2024-11-13

// Date-> 13/11/24 && 19/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = 0;

        for(int i=0; i<n; i++){
            int idx = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i])-nums.begin();
            int x = idx-1-i;
            idx = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i])-nums.begin();
            int y = idx-1-i;
            res += (y-x);
        }

        return res;
    }
};