// #Question:-

// Link-> https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26

// Date-> 26/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> vec;
    
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                    vec.push_back(grid[i][j]);
                }
            }
    
            int s = vec.size();
    
            nth_element(vec.begin(), vec.begin()+s/2, vec.end());
    
            int cnt = 0;
            int target = vec[s/2];
    
            for(auto &num : vec){
                if(num%x != target%x){
                    return -1;
                }
                cnt += abs(target-num)/x;
            }
            return cnt;
        }
    };