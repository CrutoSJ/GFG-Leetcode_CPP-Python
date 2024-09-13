// #Question:-

// Link-> https://leetcode.com/problems/xor-queries-of-a-subarray/description/?envType=daily-question&envId=2024-09-13

// Date-> 13/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int s = queries.size();
        vector<int> result(s);
        for(int i=0; i<s; i++){
            int start = queries[i][0];
            int end   = queries[i][1];
            int res = 0;
            for(int j=start; j<=end; j++){
                res ^= arr[j];
            }
            result[i] = res;
        }
        return result;
    }
};