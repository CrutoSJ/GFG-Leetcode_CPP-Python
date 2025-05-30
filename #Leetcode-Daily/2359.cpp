// #Question:-

// Link-> https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-question&envId=2025-05-30

// Date-> 30/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getDistances(int start, vector<int>& edges, int n) {
        vector<int> dist(n, -1);
        int d = 0;
        int curr = start;
        while (curr != -1 && dist[curr] == -1) { // avoid revisiting nodes
            dist[curr] = d++;
            curr = edges[curr];
        }
        return dist;
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = getDistances(node1, edges, n);
        vector<int> dist2 = getDistances(node2, edges, n);

        int ans = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};
