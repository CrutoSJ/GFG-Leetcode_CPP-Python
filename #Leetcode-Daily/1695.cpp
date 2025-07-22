// #Question:-

// Link-> https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

// Date-> 22/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cuSum(n,0);

        cuSum[0] = nums[0];

        for(int i=1; i<n; i++){
            cuSum[i] = cuSum[i-1] + nums[i];
        }

        vector<int> mp(10001, -1);
        int i = 0;
        int j = 0;
        int res = 0;

        while(j<n){
            i = max(i, mp[nums[j]]+1);
            int jSum = cuSum[j];
            int iSum = i-1 < 0 ? 0 : cuSum[i-1];
            
            res = max(res, jSum-iSum);
            mp[nums[j]] = j;
            j++;
        }

        return res;
    }
};