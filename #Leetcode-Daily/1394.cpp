// #Question:-

// Link-> https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05

// Date-> 05/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int,int> mp;

        for(int &val : arr){
            mp[val]++;
        }

        for(auto &it : mp){
            if(it.first == it.second){
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};