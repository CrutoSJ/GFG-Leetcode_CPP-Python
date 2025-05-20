// #Question:-

// Link-> https://leetcode.com/problems/zero-array-transformation-i/submissions/1639388522/?envType=daily-question&envId=2025-05-20

// Date-> 20/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n,0);

        for(auto & query : queries){
            int start = query[0];
            int end   = query[1];

            diff[start] += 1;
            if(end+1 < n){
                diff[end+1] -= 1;
            }
        }

        vector<int> op(n,0);
        int cum=0;

        for(int i=0; i<n; i++){
            cum+=diff[i];
            op[i] = cum;
        }

        for(int i=0; i<n; i++){
            if(op[i] < nums[i]){
                return false; 
            }
        }
        return true;
    }
};