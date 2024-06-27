// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

// Date-> 27/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>>& mat) {
    int n=mat.size(), m=mat[0].size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(mat[i][j]!=mat[i+1][j+1]){
                return false;
            }
        }
    }
    return true;
}