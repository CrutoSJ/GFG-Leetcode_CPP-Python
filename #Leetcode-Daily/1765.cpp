// #Question:-

// Link-> https://leetcode.com/problems/map-of-highest-peak/submissions/1516877869/?envType=daily-question&envId=2025-01-22

// Date-> 22/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{0,1}, {0,-1}, {-1,0}, {1,0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> heights(n, vector<int> (m,-1));
        queue<P> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int s = q.size();
            while(s--){
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;
                
                for(auto &dir : directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];

                    if(i_>=0 && i_<n && j_>=0 && j_<m && heights[i_][j_] == -1){
                        heights[i_][j_]=heights[i][j]+1;
                        q.push({i_,j_});
                    }
                }

            }
        }
        return heights;
    }
};