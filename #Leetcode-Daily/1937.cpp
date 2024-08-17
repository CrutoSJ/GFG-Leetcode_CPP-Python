// #Question:-

// Link-> https://leetcode.com/problems/maximum-number-of-points-with-cost/description/?envType=daily-question&envId=2024-08-17

// Date-> 17/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector< long long > prev(n);
        for(int col=0; col<n; col++){
            prev[col] = points[0][col];
        }

        for(int row=1; row<m; row++){

            vector<long long> left(n, 0);
            vector<long long> right(n, 0);

            left[0] = prev[0];
            for(int i=1; i<n; i++){
                left[i] = max(prev[i], left[i-1]-1);
            }

            right[n-1] = prev[n-1];
            for(int i=n-2; i>=0; i--){
                right[i] = max(prev[i], right[i+1]-1);
            }

            vector<long long> curr(n,0);

            for(int i=0; i<n; i++){
                curr[i] = points[row][i] + max(left[i], right[i]);
            }

            prev = curr;
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};