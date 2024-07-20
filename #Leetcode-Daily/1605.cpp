// #Question:-

// Link-> https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20

// Date-> 20/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> mat(n, vector<int>(m,0));

        int i=0;
        int j=0;

        while(i<n &&j<m){
            mat[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -=mat[i][j];
            colSum[j] -=mat[i][j];

            if(rowSum[i] == 0){
                i++;
            } else{
                j++;
            }
        }
        return mat;
    }
};