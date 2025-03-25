// #Question:-

// Link-> https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/?envType=daily-question&envId=2025-03-25

// Date-> 25/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mrgIntvl(vector<vector<int>> vec){
            int n=vec.size();
            sort(vec.begin(), vec.end());
    
            vector<vector<int>> res;
            res.push_back(vec[0]);
    
            for(int i=1; i<n; i++){
                if(vec[i][0] < res.back()[1]){
                    res.back()[1] = max(vec[i][1], res.back()[1]);
                } else{
                    res.push_back(vec[i]);
                }
            }
    
            return res;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> hor;
            vector<vector<int>> ver;
    
            for(auto &val : rectangles){
                int x1 = val[0];
                int y1 = val[1];
                int x2 = val[2];
                int y2 = val[3];
    
                hor.push_back({x1,x2});
                ver.push_back({y1,y2});
            }
    
            vector<vector<int>> res1 = mrgIntvl(hor);
            if(res1.size() >= 3){
                return true;
            }
            vector<vector<int>> res2 = mrgIntvl(ver);
            return res2.size()>=3;
        }
    };