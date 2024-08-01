// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// Date-> 01/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int> > &matrix, int rowS, int colS, vector<int> &ans){
        int top=0;
        int bottom=rowS-1;
        int left=0;
        int right=colS-1;
        
        while(top<=bottom && left<=right){
            //top-most row:-
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            //right-most col:-
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            //bottom-most row:-
            if(top<=bottom){
                for (int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            //left-most row:-
            if(left<=right){
                for (int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
                }
            left++;
            }
        }
        return ;
    }
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        if (matrix.empty()) return {};
        
        int rowS = matrix.size();
        int colS = matrix[0].size();
        vector<int>ans;
        
        solve(matrix, rowS, colS, ans);
        return ans;
    }
};