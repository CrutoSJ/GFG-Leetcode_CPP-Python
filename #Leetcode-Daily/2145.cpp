// #Question:-

// Link-> https://leetcode.com/problems/count-the-hidden-sequences/submissions/1613660727/?envType=daily-question&envId=2025-04-21

// Date-> 21/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int curr = 0;
            int maxV=0, minV=0;
    
            for(int &d : differences){
                curr+=d;
    
                minV = min(minV,curr);
                maxV = max(maxV,curr);
    
                if((upper-maxV) - (lower-minV) + 1 <= 0){
                    return 0;
                }
            }
    
            return (upper-maxV) - (lower-minV) + 1;
        }
    };