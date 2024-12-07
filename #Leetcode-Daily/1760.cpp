// #Question:-

// Link-> https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/?envType=daily-question&envId=2024-12-07

// Date-> 07/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int maxOperations, int maxBalls) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > maxBalls) {
                operations += (balls - 1) / maxBalls;
                if (operations > maxOperations) return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, maxOperations, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
