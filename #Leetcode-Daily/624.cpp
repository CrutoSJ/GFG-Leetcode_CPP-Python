// #Question:-

// Link-> https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16

// Date-> 16/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int gMin = arrays[0][0];
        int gMax = arrays[0].back();
        int maxDis = INT_MIN;

        for(int i=1; i<arrays.size(); i++){
            maxDis = max(maxDis, abs(arrays[i][0]     - gMax));
            maxDis = max(maxDis, abs(arrays[i].back() - gMin));

            gMin = min(gMin, arrays[i][0]);
            gMax = max(gMax, arrays[i].back());
        }

        return maxDis;
    }
};