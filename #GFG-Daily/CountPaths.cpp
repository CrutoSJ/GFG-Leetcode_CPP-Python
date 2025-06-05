// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-the-paths4332/1

// Date-> 05/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int dfs(int node, vector<int> &dp, vector<vector<int>> adj, int dest){
        if(node == dest){
            return 1;
        }
        
        if(dp[node] != -1){
            return dp[node];
        }
        
        int cnt = 0;
        
        for(auto &nbr : adj[node]){
            cnt += dfs(nbr, dp, adj, dest);
        }
        
        return dp[node] = cnt;
    }
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        vector<int> dp(V, -1);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
            
        return dfs(src, dp, adj, dest);
    }
};