// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Date-> 21/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> ans(N, -1);
        vector< vector<pair<int, int>> > adj(N);
        
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
  
        vector<int> vis(N, 0);
        vis[src]=1;
        ans[src]=0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int len = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it.first]){
                    vis[it.first] = 1;
                    ans[it.first] = len+1;
                    q.push({it.first, len+1});
                }
                else{
                    ans[it.first] = min(ans[it.first] , len+1);
                }
            }
        }
        return ans;
    }
};