// #Question:-

// Link-> https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/?envType=daily-question&envId=2025-07-24

// Date-> 24/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, int parent, vector<int>& subtreeXor, vector<int>& inTime, vector<int>& outTime,
            int &timer, vector<int>& nums, unordered_map<int, vector<int>>& adj) {
                
            subtreeXor[node] = nums[node];
            inTime[node] = timer;
            timer++;
            for(int &ngbr : adj[node]) {
                if(ngbr != parent) {
                    dfs(ngbr, node, subtreeXor, inTime, outTime, timer, nums, adj);
                    subtreeXor[node] ^= subtreeXor[ngbr];
                }
            }
            outTime[node] = timer;
            timer++;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    int getScore(int a, int b, int c) {
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});

        return maxXor - minXor;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subtreeXor(n,0);

        vector<int> inTime(n,0);
        vector<int> outTime(n,0);

        int timer = 0;

        dfs(0, -1, subtreeXor, inTime, outTime, timer, nums, adj);

        int result = INT_MAX;
        for(int u = 1; u < n; u++) {
            for(int v = u+1; v < n; v++) {
                int xor1;
                int xor2;
                int xor3;

                if(isAncestor(u, v, inTime, outTime)) {
                    xor1 = subtreeXor[v];
                    xor2 = subtreeXor[u] ^ subtreeXor[v];
                    xor3 = subtreeXor[0] ^ xor1 ^ xor2;
                } else if(isAncestor(v, u, inTime, outTime)) {
                    xor1 = subtreeXor[u];
                    xor2 = subtreeXor[v] ^ subtreeXor[u];
                    xor3 = subtreeXor[0] ^ xor1 ^ xor2;
                } else {
                    xor1 = subtreeXor[u];
                    xor2 = subtreeXor[v];
                    xor3 = subtreeXor[0] ^ xor1 ^ xor2;
                }

                result = min(result, getScore(xor1, xor2, xor3));
            }
        }

        return result;
    }
};