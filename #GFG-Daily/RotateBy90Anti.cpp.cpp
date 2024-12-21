// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

// Date-> 21/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for(int i=0; i<n; i++){
            int top = 0, bottom = n - 1;
            while (top < bottom) {
                swap(mat[top][i], mat[bottom][i]);
                top++;
                bottom--;
            }
        }
    }
};