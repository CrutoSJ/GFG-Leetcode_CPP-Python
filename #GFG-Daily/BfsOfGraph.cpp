// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Date-> 02/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> bfs(vector<vector<int>> &adj) {
          int n=adj.size();
          vector<int> res,vis(n,0);
          queue<int> q;
          
          q.push(0);
          
          vis[0]=1;
          
          while(!q.empty()){
              int node = q.front();
              q.pop();
              res.push_back(node);
              
              for(auto it : adj[node]){
                  if(!vis[it]){
                      q.push(it);
                      vis[it]=1;
                  }
              }
          }
          return res;
      }
  };