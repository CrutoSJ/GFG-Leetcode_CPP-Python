// #Question:-

// Link-> https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2024-11-24

// Date-> 24/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int mini = INT_MAX;
        long long sum  = 0;
        int cnt  = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<0){
                    cnt++;
                }
                if(abs(matrix[i][j])<mini){
                    mini = abs(matrix[i][j]);
                }
                sum += abs(matrix[i][j]);
            }
        }

        return cnt%2 == 0 ? sum : sum-(2*mini);
    }
};