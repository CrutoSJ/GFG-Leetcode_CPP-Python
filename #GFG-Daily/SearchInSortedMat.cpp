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
        int n=mat.size(), m=mat[0].size();
        int low=0, high=n*m-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int temp = mat[mid/m][mid%m];
            
            if(temp == x){
                return true;
            } else if(temp < x){
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        return false;
    }
};