// #Question:-

// Link -> https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

// Date -> 06/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = pow(grid.size(),2);
            vector<int> vis(n+1,0);
            int a,b;
    
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                        vis[grid[i][j]]++;
                }
            }
    
            for(int i=1; i<n+1; i++){
                if(vis[i] == 0){
                    b=i;
                } else if(vis[i] > 1){
                    a=i;
                }
            }
    
            return {a,b};
        }
    };