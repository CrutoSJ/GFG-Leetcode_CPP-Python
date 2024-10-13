// #Question:-

// Link-> https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=daily-question&envId=2024-10-13

// Date-> 13/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxEle = INT_MIN;
        vector<int> res = {-1000000, 1000000};

        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            maxEle = max(maxEle, nums[i][0]);
        }

        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();

            int minEle = top[0];
            int lstIdx = top[1];
            int idx    = top[2];

            if(maxEle - minEle < res[1] - res[0]){
                res[0] = minEle;
                res[1] = maxEle;
            }

            if(idx+1 < nums[lstIdx].size()){
                int newEle = nums[lstIdx][idx+1];
                pq.push({newEle, lstIdx, idx+1});
                maxEle = max(maxEle, newEle);
            } else{
                break;
            }
        }

        return res;
    }
};