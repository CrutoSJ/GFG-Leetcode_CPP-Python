
// #Question:-

// Given a matrix of size r*c. Traverse the matrix in spiral form.

// Link-> https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        int left=0;
        int right=c-1;
        int top=0;
        int bottom=r-1;
        vector<int>ans;
        while(top<=bottom && left<= right){
            for (int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for (int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);}
            }
            bottom--;
            if(left<=right){
                for (int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
                }
            left++;
            }
            
            
        }
        return ans;
        
    }
};
