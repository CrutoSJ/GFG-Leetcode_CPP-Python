// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Date-> 07/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      bool help(int node,vector<int>&vis,vector<int>&rec,vector<vector<int>>&adj){
        vis[node]=true;
        rec[node]=true;
        for(auto &x:adj[node])
        {
            
            if(rec[x]) return true;
            if(help(x,vis,rec,adj)) return true;
        }
        rec[node]=false;
        return false;
    }
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
          vector<vector<int>>adj(V+1);
          for(auto &x:edges)
          {
              adj[x[0]].push_back(x[1]);
          }
          vector<int>vis(V+1,false),rec(V+1,false);
          
          bool flag=false;
          for(int i=0;i<V;i++)
          {
              if(!vis[i])
              {
                  flag|=help(i,vis,rec,adj);
              }
          }
          return flag;
          
      }
  };