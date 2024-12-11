// #Question:-

// Link-> https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11

// Date-> 11/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> intervals(n);

        for(int i=0; i<n; i++){
            intervals[i] = {nums[i]-k, nums[i]+k};
        }

        sort(intervals.begin(), intervals.end());
        queue<int> q;
        int res=0;

        for(pair<int,int> &interval : intervals){
            while(!q.empty() && q.front() < interval.first){
                q.pop();
            }

            q.push(interval.second);
            res = max(res, (int)q.size());
        }
        return res;
    }
};