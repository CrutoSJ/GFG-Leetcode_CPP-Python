// #Question:-

// Link-> https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/?envType=daily-question&envId=2024-07-28

// Date->28/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n+1, INT_MAX);
        vector<int> d2(n+1, INT_MAX);
        queue<P> q;
        q.push({1,1}); // {node : frequency}
        d1[1]=0;

        while(!q.empty()){
            auto [node, freq] = q.front();
            q.pop();

            if(node == n && d2[n] != INT_MAX){
                return d2[n];
            }

            int timePassed = (freq == 1) ? d1[node] : d2[node];

            int div = timePassed/change;
            if(div % 2 == 1){ //ODD : RED
                timePassed = change * (1+div);
            }

            for(auto &nbr : adj[node]){
                if(d1[nbr] == INT_MAX){
                    d1[nbr] = timePassed + time;
                    q.push({nbr,1});
                } else if(d2[nbr] == INT_MAX && d1[nbr] != timePassed + time){
                    d2[nbr] = timePassed + time;
                    q.push({nbr,2});
                }
            }
        }
        return -1;
    }
};