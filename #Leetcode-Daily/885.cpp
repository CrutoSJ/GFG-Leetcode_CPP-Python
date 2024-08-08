// #Question:-

// Link-> https://leetcode.com/problems/spiral-matrix-iii/?envType=daily-question&envId=2024-08-08

// Date-> 08/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //4 movements possible :-
        /* right, down, left, up
        */

        vector<vector<int>> direction { {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // COST FOR MOVEMENT

        vector<vector<int>> path;
        path.push_back({rStart, cStart});

        int steps = 0;
        int dir = 0;

        while(path.size() < rows*cols){
            if(dir == 0 || dir == 2){
                steps++;
            }

            for(int cnt=0; cnt<steps; cnt++){
                rStart += direction[dir][0]; // update the movement 
                cStart += direction[dir][1]; 

                if(rStart >= 0 && rStart < rows && cStart >=0 && cStart < cols){
                    path.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;
        }
        return path;
    }
};