// #Question:-

// Link-> https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26

// Date-> 26/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        static long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long count = 0;
            int mini = -1, maxi = -1;
            int size = nums.size();
    
            int left = 0, right = 0;
            while (left <= right && right < size) {
                int n = nums[right];
    
                if (n < minK || n > maxK) {
                    left = right + 1;
                    right++;
                    continue;
                }
                if (n == minK) mini = right;
                if (n == maxK) maxi = right;
    
                count += max(min(maxi, mini) - left + 1, 0);
                right++;
            }
            return count;
        }
    };