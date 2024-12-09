// #Question:-

// Link-> https://leetcode.com/problems/special-array-ii/description/?envType=daily-question&envId=2024-12-09

// Date-> 09/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxReach(n);
        int end = 0;

        for (int start = 0; start < n; start++) {
            end = max(end, start);

            while (end < n - 1 && nums[end] % 2 != nums[end + 1] % 2) {
                ++end;
            }
            maxReach[start] = end;
        }

        vector<bool> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            ans[i] = end <= maxReach[start];
        }
        return ans;
    }
};