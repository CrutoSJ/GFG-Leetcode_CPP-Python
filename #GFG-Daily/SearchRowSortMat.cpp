// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1

// Date-> 23/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int row=0;
        
        while(row<mat.size()){
        int low=0, high=mat[0].size()-1, mid=0;
            while(low<=high){
                mid = low + (high-low)/2;
                int temp = mat[row][mid];
                if(temp == x){
                    return true;
                } else if(temp > x){
                    high = mid-1;
                } else{
                    low = mid+1;
                }
            }
            row++;
        }
        return false;
    }
};