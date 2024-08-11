// #Question:-

// Link-> https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11

// Date-> 11/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] == true || grid[i][j] == 0){
            return ;
        }

        vis[i][j] = true;

        dfs(grid, i+1, j,   vis);
        dfs(grid, i-1, j,   vis);
        dfs(grid, i  , j+1, vis);
        dfs(grid, i  , j-1, vis);

    }

    int cntIsland(vector<vector<int>> grid){
        int island=0;

        vector<vector<bool>> vis(n, vector<bool>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 & vis[i][j] != true){
                    dfs(grid, i, j, vis);
                    island++;
                }
            }
        }

        return island;
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int islands = cntIsland(grid);
        if(islands != 1) return 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    islands = cntIsland(grid);
                    if(islands != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};