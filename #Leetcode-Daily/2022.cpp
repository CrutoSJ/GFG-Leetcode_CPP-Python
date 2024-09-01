// #Question:-

// Link-> https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01

// Date-> 01/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        if(s != m*n){
            return {};
        }
        vector<vector<int>> result(m, vector<int>(n));
        int idx=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(idx < s){
                    result[i][j] = original[idx];
                    idx++;
                }
            }
        }
        return result;
    }
};