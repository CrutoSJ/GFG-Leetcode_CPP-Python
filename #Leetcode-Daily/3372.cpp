// #Question:-

// Link-> https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-question&envId=2025-05-28

// Date-> 28/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(int node, int parent, int d, unordered_map<int, vector<int>> &adj){
        if(d<0){
            return 0;
        }
        int cnt = 1;

        for(auto &nbr : adj[node]){
            if(nbr!=parent){
                cnt+= dfs(nbr, node, d-1, adj);
            }
        }
        return cnt;
    }
    int bfs(int node, int N, int d, unordered_map<int, vector<int>> &adj){
        queue<pair<int,int>> q;
        q.push({node,0});
        vector<int> vis(N, 0);
        vis[node] = 1;
        int count = 0;

        while(!q.empty()){
            auto front = q.front();
            int node = front.first;
            int dis = front.second;
            q.pop();

            if(dis>d){
                continue;
            }

            count++;

            for(auto &nbr : adj[node]){
                if(!vis[nbr]){
                    q.push({nbr, dis+1});
                    vis[nbr] = 1;
                }
            }
        }
        return count;
    }
    vector<int> findCount(vector<vector<int>>& edges, int d, int n){
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            ans[i] = bfs(i, n, d, adj);
        }

        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector<int> res1 = findCount(edges1, k, n);
        vector<int> res2 = findCount(edges2, k-1, m);

        int maxi = *max_element(res2.begin(), res2.end());

        for(int i=0; i<res1.size(); i++){
            res1[i] += maxi;
        }
        return res1;
    }
};