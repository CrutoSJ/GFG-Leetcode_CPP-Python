// #Question:-

// Link-> https://leetcode.com/problems/modify-graph-edge-weights/description/?envType=daily-question&envId=2024-08-30

// Date-> 30/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int LARGE_VAL = 2e9;

    long long DAlgo(vector<vector<int>>& edges, int n, int src, int dst){
        unordered_map<long long, vector<pair<long, long>>> adj;
        for(auto &edge : edges){
            if(edge[2] != -1){
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }

        vector<long long> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue< pair<long, long> , vector<pair<long, long>>, greater<pair<long, long>>> minHeap;
        minHeap.push({0, src});

        while(!minHeap.empty()){
            auto front = minHeap.top();
            minHeap.pop();

            int node = front.second;
            int curDis = front.first;

            for(auto &nbr : adj[node]){
                    if(curDis + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = curDis + nbr.second;
                        minHeap.push({dist[nbr.first], nbr.first});
                    }
            }
        }

        return dist[dst];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
        long long shortPath = DAlgo(edges, n, source, destination);

        if(shortPath < target){
            return {};
        }

        bool isMatch = (shortPath==target);

        if(shortPath >= target){
            for(auto &edge : edges){
                if(edge[2] == -1){
                    edge[2] = (isMatch==true) ? LARGE_VAL : 1;

                    if(isMatch != true){
                        long long curShortPath = DAlgo(edges, n, source, destination);

                        if(curShortPath<=target){
                            isMatch=true;
                            edge[2] += (target-curShortPath);
                        }
                    }
                }
            }
        }

        if(isMatch == false){
            return {};
        }
        return edges;

    }
};