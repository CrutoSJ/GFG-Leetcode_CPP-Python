// #Question:-

// Link-> https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

// Date-> 15/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();

        for(int i=0; i<n; i++){
            if(i==0 || groups[i] != groups[i-1]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};