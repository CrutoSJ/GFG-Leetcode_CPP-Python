// #Question:-

// Link-> https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2025-06-18

// Date-> 18/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res = {};
        sort(nums.begin(), nums.end());

        for(int i=0; i<n/3; i++){
            vector<int> curr;
            int idx = i*(3);
            for(int j=idx; j<(idx+3); j++){
                curr.push_back(nums[j]);
            }
            if(curr[2] - curr[0] > k) return {};
            res.push_back(curr);
        }
        return res;
    }
};