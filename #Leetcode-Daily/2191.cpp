// #Question:-

// Link-> https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24

// Date-> 24/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findNum(vector<int> &mapping, string nums){
        int ans = 0;
        for(int i=0; i<nums.length(); i++){
            int idx = nums[i]-'0';
            int mappDigit = mapping[idx];
            ans = ans*10+mappDigit;
        }
        return ans;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>mp;
        for(int i=0; i<nums.size(); i++){
            int num = findNum(mapping, to_string(nums[i]));
            mp.push_back({nums[i],num});
        }
        sort(mp.begin(), mp.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second < b.second;
        });

        for(int i=0; i<nums.size(); i++){
            nums[i] = mp[i].first;
        }

        return nums;
    }
};