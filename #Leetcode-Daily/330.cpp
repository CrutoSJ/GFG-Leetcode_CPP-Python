// #Question:-

// Link-> https://leetcode.com/problems/patching-array/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        int totalPatches = 0;
        long long sum = 1;
        while(sum<=n){
            sum+=(i<nums.size() && nums[i]<=sum)?nums[i++]:sum;
            totalPatches++;
        }
        return totalPatches-i;
    }
};