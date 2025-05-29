// #Question:-

// Link-> https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-question&envId=2025-05-29

// Date-> 29/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int bfs(int node, unordered_map<int, vector<int>> &adj, int div){
        int V = adj.size();
        queue<pair<int,int>> pq;
        pq.push({node, 0});
        vector<int> vis(V, 0);
        vis[node] = 1;
        int cntEven = 0;
        int cntOdd = 0;

        while(!pq.empty()){
            auto front = pq.front();
            pq.pop();
            int node = front.first;
            int dis  = front.second;

            if(dis%2 == 0){
                cntEven++;
            } else if(dis%2 != 0){
                cntOdd++;
            }

            for(auto &nbr : adj[node]){
                if(!vis[nbr]){
                    pq.push({nbr, dis+1});
                    vis[nbr] = 1;
                }
            }
        }

        return div==2?cntEven:cntOdd;
    }
    vector<int> findCount(vector<vector<int>>& edges, int s, int div){
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(s);

        for(int i=0; i<s; i++){
            ans[i] = bfs(i, adj, div);
        }

        for(int i=0; i<s; i++){
            cout << ans[i] << " ";
        }

        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector<int> res1 = findCount(edges1, n, 2);
        cout << endl;
        vector<int> res2 = findCount(edges2, m, 3);

        int maxi = *max_element(res2.begin(), res2.end());

        for(int i=0; i<res1.size(); i++){
            res1[i] += maxi;
        }

        return res1;
    }
};
