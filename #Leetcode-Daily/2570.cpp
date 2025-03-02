// #Question:-

// Link -> https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

// Date -> 02/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> res;
            map<int,int> mp;
    
            for(auto &num : nums1){
                mp[num[0]] = num[1];
            }
    
            for(auto &num : nums2){
                mp[num[0]] += num[1];
            }
    
            for(auto it: mp){
                res.push_back({it.first, it.second});
            }
            return res;
        }
    };