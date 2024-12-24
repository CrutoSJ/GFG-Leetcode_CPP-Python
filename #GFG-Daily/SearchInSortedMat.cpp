// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

// Date-> 24/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int i=0, j=mat[0].size()-1, n=mat.size();
        while(i<n && j>=0){
            int temp = mat[i][j];
            if(temp == x){
                return true;
            } else if(temp < x){
                i++;
            } else{
                j--;
            }
        }
        return false;
    }
};