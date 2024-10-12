// #Question:-

// Link-> https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12

// Date-> 12/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; i++){
            int currL = intervals[i][0];
            int currR = intervals[i][1];

            if(!pq.empty()){
                if(pq.top()<currL){
                    pq.pop();
                }
            }
            pq.push(currR);  
        }
        return pq.size();
    }
};