// #Question:-

// Link-> https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/?envType=daily-question&envId=2024-11-22

// Date-> 22/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patrnFreq;

        for (auto& curRow : matrix) {
            string patBuilder = "";

            for (int col = 0; col < curRow.size(); col++) {
                if (curRow[0] == curRow[col]) {
                    patBuilder += "T";
                } else {
                    patBuilder += "F";
                }
            }

            patrnFreq[patBuilder]++;
        }

        int maxFreq = 0;
        for (auto& data : patrnFreq) {
            maxFreq = max(data.second, maxFreq);
        }

        return maxFreq;
    }
};