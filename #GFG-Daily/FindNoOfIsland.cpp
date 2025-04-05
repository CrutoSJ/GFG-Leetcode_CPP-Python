// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Date-> 05/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int m;
      int n;
      vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1},{0,0},{-1,-1},{1,1},{-1,1},{1,-1}};
      
      void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
          
          queue<pair<int,int>> q;
          q.push({i,j});
          visited[i][j] = true;
          
          auto isSafe = [&](int x, int y) {
              return x < m && x >= 0 && y < n && y >= 0 && grid[x][y] == 'L' && visited[x][y] == false ;
          };
          
          while(!q.empty()){
              int i = q.front().first;
              int j = q.front().second;
              q.pop();
              
              for(auto& dir : directions){
                  int x = i + dir[0];
                  int y = j + dir[1];
                  if(isSafe(x,y)){
                      visited[x][y] = true;
                      q.push({x,y});
                  }
              }
          }
      }
      int countIslands(vector<vector<char>>& grid) {
          
           m = grid.size();
           n = grid[0].size();
          vector<vector<bool>> visited(m,vector<bool>(n,false));
          
          int count = 0;
          
          for(int i=0; i<m; i++){
              for(int j=0; j<n; j++){
                  if(grid[i][j] == 'L' && visited[i][j] == false){
                      bfs(grid,visited,i,j);
                      count++;
                  }
              }
          }
          return count;
      }
  };
