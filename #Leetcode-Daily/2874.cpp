// #Question:-

// Link-> https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/?envType=daily-question&envId=2025-04-03

// Date-> 03/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long res = 0, imax = 0, dmax = 0;
            for (int k = 0; k < n; k++) {
                res = max(res, dmax * nums[k]);
                dmax = max(dmax, imax - nums[k]);
                imax = max(imax, static_cast<long long>(nums[k]));
            }
            return res;
        }
    };