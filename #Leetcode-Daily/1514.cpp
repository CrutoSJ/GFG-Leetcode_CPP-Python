// #Question:-

// Link-> https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-27

// Date-> 27/08/24

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].emplace_back(v, prob);
            adj[v].emplace_back(u, prob);
        }

        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            int currNode    = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for (auto &nbr : adj[currNode]) {
                double adjProb = nbr.second;
                int adjNode = nbr.first;

                if(dist[adjNode] < currProb*adjProb){
                    dist[adjNode] = currProb*adjProb;
                    pq.push({dist[adjNode],adjNode});
                }
                
            }
        }
        return dist[end_node];
    }
};