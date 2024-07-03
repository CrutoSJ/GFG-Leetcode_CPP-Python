// #Question:-

// Link-> https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

// Date-> 03/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i=0; i<4; i++){
            int j = nums.size()-4+i;
            ans = min(ans, nums[j]-nums[i]);
        }
        return ans;
    }
};