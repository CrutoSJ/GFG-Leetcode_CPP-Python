// #Question:-

// Link-> https://leetcode.com/problems/best-sightseeing-pair/?envType=daily-question&envId=2024-12-27

// Date-> 27/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxL = values[0];
        int res  = INT_MIN;

        for(int j=1; j<values.size(); j++){
            res  = max(res, maxL+values[j]-j);
            maxL = max(maxL, values[j]+j);
        }
        return res;
    }
};