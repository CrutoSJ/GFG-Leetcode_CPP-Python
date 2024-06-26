// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

// Date-> 26/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int cnt=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(matrix[row][col]==1) continue;
                if(col!=0 && matrix[row][col-1]==1)cnt++;
                if(col!=m-1 && matrix[row][col+1]==1)cnt++;
                if(row!=0 && matrix[row-1][col]==1)cnt++;
                if(row!=n-1 && matrix[row+1][col]==1)cnt++;
            }
        }
        return cnt;
    }
};