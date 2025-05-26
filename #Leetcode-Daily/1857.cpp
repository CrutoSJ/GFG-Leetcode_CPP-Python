// #Question:-

// Link-> https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-question&envId=2025-05-26

// Date-> 26/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int n = colors.size();
        vector<int> inDeg(n, 0);
        vector<vector<int>> t(n, vector<int> (26,0));
        int maxClr = 0;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        int cnt=0;

        for(int i=0; i<n; i++){
            if(inDeg[i] == 0){
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            maxClr = max(maxClr, t[node][colors[node]-'a']);

            for(auto &nbr : adj[node]){

                for(int i=0; i<26; i++){
                    t[nbr][i] = max(t[nbr][i], t[node][i] + (colors[nbr] - 'a' == i));
                }

                inDeg[nbr]--;
                if(inDeg[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        if(cnt != n) return -1;
        return maxClr;
    }
};