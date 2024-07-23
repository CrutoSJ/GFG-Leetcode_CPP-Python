// #Question:-

// Link-> https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23

// Date-> 23/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &node : nums){
            mp[node]++;
        }

        sort(nums.begin(), nums.end(), [&](int &a, int &b){
            if(mp[a]==mp[b]){
                return a>b;
            }
            return mp[a] < mp[b];
        });
        return nums;
    }
};