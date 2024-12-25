// #Question:-

// Date-> 25/12/24

// Link-> https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size();
        bool colZ=false, rowZ=false;
        
        for(int i=0; i<m; i++){
            if(mat[0][i] == 0){
                rowZ=true;
                break;
            }
        }
        
        for(int i=0; i<n; i++){
            if(mat[i][0] == 0){
                colZ=true;
                break;
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0; 
                }
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        if(rowZ){
            for(int i=0; i<m; i++){
                mat[0][i] = 0;
            }
        }
        
        if(colZ){
            for(int j=0; j<n; j++){
                mat[j][0] = 0;
            }
        }
    }
};