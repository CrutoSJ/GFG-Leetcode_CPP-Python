// #Question:-

// Link-> https://leetcode.com/problems/set-matrix-zeroes/description/?envType=daily-question&envId=2025-05-21

// Date-> 21/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int col0 = 1;
        
        //row - mat[..][0]
        //colum - mat[0][..]
        
        //step 1 -> traversing and marking row[0] & col[0].
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    mat[i][0] = 0;
                    if(j!=0){
                        mat[0][j] = 0;
                    } else{
                        col0 = 0;
                    }
                }
                
            }
        }
        
        //step 2-> traverse and marks 0's.
        for(int i=1; i<mat.size(); i++){
            for(int j=1; j<mat[0].size(); j++){
                if(mat[i][j] != 0){
                    if(mat[0][j] == 0 || mat[i][0] == 0){
                        mat[i][j] = 0;
                    }
                }
            }
        }
        
        //step-> 3
        if(mat[0][0] == 0){
            for(int j=0; j<mat[0].size(); j++){
                mat[0][j] = 0;
            }
        }
        
        if(col0 == 0){
            for(int i=0; i<mat.size(); i++){
                mat[i][0] = 0;
            }
        }
            
    }
};