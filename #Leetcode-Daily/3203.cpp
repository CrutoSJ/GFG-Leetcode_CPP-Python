// #Question:-

// Link-> https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/?envType=daily-question&envId=2024-12-24

// Date-> 24/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> BFS(unordered_map<int, vector<int>> &adj, int source){
        queue<int> q;
        q.push(source);

        unordered_map<int,bool> vis;
        vis[source] = true;

        int distance=0;
        int farthestNode = source;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                farthestNode = curr;

                for(auto &nbr : adj[curr]){
                    if(vis[nbr] == false){
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }

            if(!q.empty()){
                distance++;
            }
        }
        return {farthestNode, distance};
    }

    int findDiameter(unordered_map<int, vector<int>> &adj){
        //Step 1-> find max dist from any random node, let it be U and node B
        auto[farthestNode, dist] = BFS(adj, 0);

        //Step2-> That node B would be one of the diameter end node, then again call BFS

        //Step 3-> finding max distance node from B, i.e would be other end of diameter
        auto[otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>> &edges){
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, combined}); 
    }
};