// #Question:-

// Given a 2D binary matrix(1-based indexed) a of dimensions nxm , determine the row that contains the minimum number of 1's.
// Note: The matrix contains only 1's and 0's. Also, if two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.

// Link -> https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int count = 0;
        vector<int>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]==1){
                    count ++;
                }
            }
            ans.push_back(count);
            count = 0;
        }
        
        int min = *min_element(ans.begin(), ans.end());
        
        for(int i=0; i<ans.size(); i++){
            if(ans[i]==min){
                return i+1;
            }
        }
        
        return 1;
        
    }
};