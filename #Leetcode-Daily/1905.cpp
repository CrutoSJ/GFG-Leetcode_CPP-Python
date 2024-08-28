// #Question:-

// Link-> https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28

// Date-> 28/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size()){
            return true;
        }
        if(grid2[i][j] != 1){
            return true;
        }

        grid2[i][j] = -1;

        bool result = (grid1[i][j] == 1);

        result = result & checkSubIsland(grid1, grid2, i+1, j);
        result = result & checkSubIsland(grid1, grid2, i-1, j);
        result = result & checkSubIsland(grid1, grid2, i, j+1);
        result = result & checkSubIsland(grid1, grid2, i, j-1);

        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands = 0;
        int n = grid2.size();
        int m = grid2[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)){
                    subIslands++;
                }
            }
        }
        return subIslands;
    }
};