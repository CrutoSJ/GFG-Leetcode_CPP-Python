// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

// Date-> 22/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int i=0, j=mat[0].size()-1, n=mat.size();
        while(i<n && j>=0){
            int val = mat[i][j];
            if(val==x)return true;
            else if(val<x)i++;
            else j--;
        }
        return false;
    }
};