// #Question:-

// Link-> https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

// Date-> 23/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int commSerCnt = 0;
        vector<int> rCnt(grid[0].size(), 0), lSerCol(grid.size(), -1);

        for(int row=0; row<grid.size(); row++){
            int serCntRow=0;
            for(int col=0; col<grid[0].size(); col++){
                if(grid[row][col]){
                    serCntRow++;
                    rCnt[col]++;
                    lSerCol[row]=col;
                }
            }

            if(serCntRow!=1){
                commSerCnt += serCntRow,
                lSerCol[row]=-1;
            }
        }

        for(int row=0; row<grid.size(); row++){
            commSerCnt += lSerCol[row] != -1 && rCnt[lSerCol[row]] > 1;
        }

        return commSerCnt;
    }
};