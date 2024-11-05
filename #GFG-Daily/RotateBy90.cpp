// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

// Date-> 05/11/24

// #Solution:

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& mat) {
    int n = mat[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(mat[i][j], mat[i][n-j-1]);
        }
    }
}
