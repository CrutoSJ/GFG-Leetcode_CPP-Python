// #Question:-

// Link-> https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/?envType=daily-question&envId=2024-11-07

// Date-> 07/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;

        for(int i=0; i<24; i++){
            int curBitCnt = 0;
            for(auto &num : candidates){
                if((num & (1<<i)) != 0){
                    curBitCnt += 1;
                }
            }
            result = max(result, curBitCnt);
        }
        return result;
    }
};