// #Question:-

// Link-> https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26

// Date-> 26/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int len = 0;
        int powerVal = 1;

        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                len++;
            } else if(powerVal <= k){
                k -= powerVal;
                len++;
            }

            if(powerVal <= k){
                powerVal = powerVal << 1;
            }
        }

        return len;
    }
};