// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/decode-the-string2444/1

// Date-> 01/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            vector<int> modifiedNums;
    
            for (int index = 0; index < n - 1; index++) {
                if (nums[index] == nums[index + 1] && nums[index] != 0) {
                    nums[index] *= 2;
                    nums[index + 1] = 0;
                }
            }
    
            for (int num : nums) {
                if (num != 0) {
                    modifiedNums.push_back(num);
                }
            }
    
            while (modifiedNums.size() < n) {
                modifiedNums.push_back(0);
            }
    
            return modifiedNums;
        }
    };