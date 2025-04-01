// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Date-> 01/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void solve(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &ans){
          vis[node]=1;
          ans.push_back(node);
          for(auto &it: adj[node]){
              if(vis[it]==0){
                  solve(it,adj,vis,ans);
              }
          }
      }
      vector<int> dfs(vector<vector<int>>& adj) {
          int n=adj.size();
          vector<int> vis(n,0);
          vector<int> ans;
          int start=0;
          solve(start,adj,vis,ans);
          return ans;
      }
  };