// #Question:-

// Link-> https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/?envType=daily-question&envId=2024-11-27

// Date-> 27/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(int n, unordered_map<int, vector<int>> &adj){
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,0);
        vis[0] = 1;
        int lvl = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();

                if(top == n-1){
                    return lvl;
                }

                for(auto &nbr : adj[top]){
                    if(vis[nbr] != 1){
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1); 
        }

        vector<int> res;

        for(auto &query : queries){
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            int d = bfs(n, adj);
            res.push_back(d);
        }
        return res;
    }
};