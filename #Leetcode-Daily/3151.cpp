// #Question:-

// Link-> https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01

// Date-> 01/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Iterate through indexes 0 to n - 1
        for (int index = 0; index < nums.size() - 1; index++) {
            // Compare the parities of the current and next number
            if (nums[index] % 2 == nums[index + 1] % 2) {
                // If the two adjacent numbers have the same parity, return
                // false
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are
        // found
        return true;
    }
};