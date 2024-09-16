// #Question:-

// Link-> https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16

// Date-> 16/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i=0; i<n; i++){
            string time = timePoints[i];

            int hour = stoi(time.substr(0,2));
            int min  = stoi(time.substr(3));

            minutes[i] = hour*60 + min;
        }

        sort(minutes.begin(), minutes.end());

        int res = INT_MAX;

        for(int i=1; i<n; i++){
            res = min(res, minutes[i] - minutes[i-1]);
        }

        return min(res, 24*60 - minutes[n-1] + minutes[0]);
        
    }
};