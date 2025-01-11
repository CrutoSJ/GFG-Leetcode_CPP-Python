// #Question:-

// Link-> https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11

// Date-> 11/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int len=s.size();

        if(len<k)return false;
        if(len==k)return true;

        int oddCnt=0;

        for(char &ch: s){
            oddCnt ^= 1 << (ch-'a');
        }

        int res = __builtin_popcount(oddCnt);

        return res<=k;
    }
};