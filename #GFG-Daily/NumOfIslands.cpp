// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Date-> 06/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        // 8 directions :- top-bottom, left-right, 4 diagonals
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] == 1 || grid[i][j] == '0') {
            return ;
        }
        
        if(grid[i][j] == '1'){
            vis[i][j] = 1;
        }
        
        solve(i+1, j, grid, vis);
        solve(i-1, j, grid, vis);
        solve(i, j+1, grid, vis);
        solve(i, j-1, grid, vis);
        solve(i+1, j+1, grid, vis);
        solve(i+1, j-1, grid, vis);
        solve(i-1, j+1, grid, vis);
        solve(i-1, j-1, grid, vis);
        
        return ;
        
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int res = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] != 1){
                    res++;
                    solve(i, j, grid, vis);
                }
            }
        }
        
        return res;
    }
};