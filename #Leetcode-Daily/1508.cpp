// #Question:-

// Link-> https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9+7;
        vector<int> subSum;
        subSum.push_back(0);

        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                subSum.push_back(sum);
            }
        }

        sort(subSum.begin(), subSum.end());

        int ans = 0;

        for(int i=left; i<=right; i++){
            ans = (ans + subSum[i]) % MOD;
        }

        return ans;
        
    }
};