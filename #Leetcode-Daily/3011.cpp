// #Question:-

// Link-> https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06

// Date-> 06/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> values = nums;
        for (int i = 0; i < n - 1; i++) {
            if (values[i] <= values[i + 1]) {
                continue;
            } else {
                if (__builtin_popcount(values[i]) ==
                    __builtin_popcount(values[i + 1])) {
                    swap(values[i], values[i + 1]);
                } else {
                    return false;
                }
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (values[i] >= values[i - 1]) {
                continue;
            } else {
                if (__builtin_popcount(values[i]) ==
                    __builtin_popcount(values[i - 1])) {
                    swap(values[i], values[i - 1]);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};