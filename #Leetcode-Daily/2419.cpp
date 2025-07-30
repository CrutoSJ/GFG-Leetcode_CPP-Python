// #Question:-

// Link-> https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14

// Date-> 14/09/24 && 30/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result, maxLen, maxEle = 0;
        for(auto &num : nums){
            if(num > maxEle){
                maxEle = num; 
                maxLen = 0;
                result = 0;
            }

            if(maxEle == num){
                maxLen++;
            }

            else{
                maxLen = 0;
            }

            result = max(result, maxLen);
        }
        return result;
    }
};