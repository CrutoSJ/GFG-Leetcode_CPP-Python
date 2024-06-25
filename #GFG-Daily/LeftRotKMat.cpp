// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1

// Date-> 25/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        for(auto &row: mat){
            reverse(row.begin(), row.begin()+k);
            reverse(row.begin()+k,row.end());
            reverse(row.begin(), row.end());
        }
        return mat;
    }
};