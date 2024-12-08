// #Question:-

// Link-> https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2024-12-08

// Date-> 08/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());

        int maxVal = 0, maxSum = 0;

        for (auto& event : events) {
            while (pq.size() && pq.top().first < event[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }

        return maxSum;
    }
};