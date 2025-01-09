// #Question:-

// Link-> https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09

// Date-> 09/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(string &word:words){
            if(word.find(pref) == 0)cnt++;
        }
        return cnt;
    }
};