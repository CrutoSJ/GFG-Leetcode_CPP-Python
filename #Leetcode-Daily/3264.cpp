// #Question:-

// Link-> https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/?envType=daily-question&envId=2024-12-16

// Date-> 16/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }

        while(k--){
            pair<int,int> top = pq.top();
            pq.pop();

            int val = top.first;
            int idx = top.second;

            nums[idx] *= multiplier;
            pq.push({val*multiplier, idx});
        }
        return nums;
    }
};