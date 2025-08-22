// #Question:-

// Link-> https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/?envType=daily-question&envId=2025-08-22

// Date-> 22/08/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minR = n, maxR = -1, minC = m, maxC = -1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    minR = min(minR, i);
                    maxR = max(maxR, i);
                    minC = min(minC, j);
                    maxC = max(maxC, j);
                }
            }
        }
        // cout << maxR << " " << minR << " " << maxC << " " << minC;
        return (maxR - minR + 1) * (maxC - minC + 1);
    }
};