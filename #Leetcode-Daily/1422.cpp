// #Question:-

// Link-> https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

// Date-> 01/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int zeros=0, ones=0, res=INT_MIN;

        for(int i=0; i<n-1; i++){
            if(s[i]=='0')zeros++;
            else ones++;
            res = max(res, zeros-ones);
        }

        if(s[n-1] == '1')ones++;
        return res+ones;
    }
};