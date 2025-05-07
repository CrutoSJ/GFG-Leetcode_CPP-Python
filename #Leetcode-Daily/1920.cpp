// #Question:-

// Link-> https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06

// Date-> 06/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int a = nums.size();
            vector<int> ans(a);
            for(int i=0; i<a; i++){
                ans[i] = nums[nums[i]];
            }
            return ans;
        }
    };