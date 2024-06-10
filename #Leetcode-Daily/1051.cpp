// #Question:-

// Link-> https://leetcode.com/problems/height-checker/

// Date-> 10/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected;
        expected = heights;
        sort(expected.begin(), expected.end());
        int count = 0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i]!=expected[i]) 
                count++;
        }
        return count;
    }
};