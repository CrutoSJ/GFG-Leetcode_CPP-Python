// #Question:-

// Link-> https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

// Date-> 19/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int>mins;
        unordered_set<int>maxs;

        for(int i=0; i<matrix.size(); i++){//for min in rows
            int mini = INT_MAX;
            for(int j=0;j<matrix[i].size(); j++){
                mini = min(matrix[i][j], mini);
            }
            mins.insert(mini);
        }

        for(int i=0; i<matrix[0].size(); i++){//for max in cols
            int maxi = INT_MIN;
            for(int j=0; j<matrix.size(); j++){
                maxi = max(matrix[j][i], maxi);
            }
            maxs.insert(maxi);
        }

        for(auto & i:mins){// to find the common element
            if(maxs.find(i) != maxs.end()){
                return {i};
            }
        }

        return {};
    }
};