// #Question:-

// Link-> https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01

// Date-> 01/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int res = 1;

        for(int i=1; i<n; i++){
            if(word[i-1] == word[i]){
                res++;
            }
        }

        return res;
    }
};