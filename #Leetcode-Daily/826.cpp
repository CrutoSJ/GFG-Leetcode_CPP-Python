// #Question:-

// Link->  https://leetcode.com/problems/most-profit-assigning-work/

//Date-> 18/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vec(difficulty.size());
        for(int i=0; i<difficulty.size(); i++){
            vec[i] = {difficulty[i], profit[i]};
        }
        auto comp = [&](pair<int,int> a, pair<int,int> b){
            if(a.first < b.first)return true;
            return false;
        };
        sort(vec.begin(), vec.end(), comp);
        sort(worker.begin(), worker.end());
        int res = 0;
        int cov = 0;
        int maxProf = 0;
        for(int i=0; i<worker.size(); i++){
            int getMid = binarySearch(vec, worker[i]);
            for(int i=cov; i<=getMid; i++){
                maxProf = max(maxProf, vec[i].second);
            }
            cov = max(0,getMid);
            res += maxProf;
        }
        return res;
    }
    int binarySearch(vector<pair<int,int>>& vec,int target){
        int l = 0;
        int r = vec.size()-1;
        int res = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(vec[mid].first <= target){
                res = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            } 
        }
        return res;
    }
};