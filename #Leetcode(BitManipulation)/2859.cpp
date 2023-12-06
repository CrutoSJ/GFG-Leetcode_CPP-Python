// #Question:-

// You are given a 0-indexed integer array nums and an integer k.

// Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.

// The set bits in an integer are the 1's present when it is written in binary.

// For example, the binary representation of 21 is 10101, which has 3 set bits.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int index = i;
            int count = 0;
            
            while (index > 0) {
                if (index % 2 == 1) {
                    count++;
                }
                index /= 2;
            }
            
            if (count == k) {
                result += nums[i];
            }
        }
        
        return result;
    }
};