// #Question:-

// Link-> https://leetcode.com/problems/score-of-a-string/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i=0; i<s.length()-1; i++){
            sum += abs((s[i]-'0') - (s[i+1]-'0')); 
        }
        return sum;
    }
};