// #Question:-

// Link-> https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=daily-question&envId=2025-06-19

// Date-> 19/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int mini = nums[0];

        for(int i=0; i<n; i++){
            if(nums[i]-mini > k){
                cnt++; 
                mini = nums[i];
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int partitionArray(vector<int>& nums, int k) {
        const int MAX_VAL = 1e5 + 1;
        vector<bool> exists(MAX_VAL, false);

        for (int num : nums) {
            exists[num] = true;
        }

        int cnt = 0;
        for (int i = 0; i < MAX_VAL; ++i) {
            if (exists[i]) {
                cnt++;  // start a new group from here
                // skip all elements in this group range [i, i + k]
                i = i+k;
            }
        }
        return cnt;
    }
};

