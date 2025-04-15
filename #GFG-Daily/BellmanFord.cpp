// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Date-> 15/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          vector<int>dist(V, 1e8);
          dist[src]=0;
          
          for(int i=0; i<V; i++){
              bool relaxed=0;
              for(auto &it:edges){
                  int u=it[0];
                  int v=it[1];
                  int w=it[2];
                  if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                      relaxed=1;
                      dist[v]=w+dist[u];
                  }
              }
          }
          
          for(auto &it:edges){
              int u=it[0];
              int v=it[1];
              int w=it[2];
              if(dist[u]!=1e8 && dist[v]>w+dist[u]){
                  return {-1};
              }
          }
          return dist;
          
      }
  };