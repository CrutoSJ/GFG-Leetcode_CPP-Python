// #Question:-

// Link-> https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13

// Date-> 13/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };

    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        unordered_map<int,bool> vis;
        
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
            vis[i] = false;
        }

        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();

            int arrVal = top.first;
            int arrIdx = top.second;

            if(vis[arrIdx])continue;

            score += arrVal;
            vis[arrIdx] = true;

            if (arrIdx - 1 >= 0) {
                vis[arrIdx - 1] = true;
            }
            if (arrIdx + 1 < nums.size()) {
                vis[arrIdx + 1] = true;
            }           
        }
        return score;
    }
};