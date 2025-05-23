// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Date-> 06/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> topoSort(int n, vector<vector<int>>& edges) {
          vector<vector<int>>adj(n+1); 
          
          for(auto it:edges)
          {
              adj[it[1]].push_back(it[0]);
          }
          vector<int>ans;
          vector<int>vis(n+1,0);
          function<void(int)>f=[&](int u)->void{
             
             
             vis[u]=1;
             for(int v:adj[u])
             {
                 if(!vis[v])
                 {
                     f(v);
                 }
             }
             ans.push_back(u);
          };
          for(int i=0;i<n;i++)
          {
              if(!vis[i])
              {
                  f(i);
              }
          }
          return ans;
      }
  };