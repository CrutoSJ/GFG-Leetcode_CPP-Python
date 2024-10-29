// #Question:-

// Link-> https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29

// Date-> 29/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<int>directions = {-1,0,1};
    int dfs(int row, int col, vector<vector<int>> &grid,vector<vector<int>> &t){
        if(t[row][col] != -1){
            return t[row][col];
        }

        int moves = 0;
        for(int &dir : directions){
            int nRow = row+dir;
            int nCol = col+1;

            if(nRow >=0 && nRow<m && nCol >=0 && nCol <n && grid[nRow][nCol] > grid[row][col]){
                moves = max(moves, 1+dfs(nRow, nCol, grid, t));
            }
        }
        return t[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m =grid.size();
        n =grid[0].size();

        vector<vector<int>> t(m, vector<int>(n,-1));

        int result = 0;

        for(int row=0; row<m; row++){
            result = max(result, dfs(row, 0, grid, t));
        }

        return result;
    }
};