// #Question:-

// Link-> https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22

// Date-> 22/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>mp;
        int n = names.size();
        for(int i=0; i<n; i++){
            mp.push_back({names[i], heights[i]});
        }
        sort(mp.begin(), mp.end(), [](const pair<string, int>&a, const pair<string, int>&b){
            return a.second > b.second;
        });

        vector<string>ans;
        for(auto &i : mp){
            ans.push_back(i.first);
        }
        return ans;
    }
};