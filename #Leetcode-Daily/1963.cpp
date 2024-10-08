// #Question:-

// Link-> https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08

// Date-> 08/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int len = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '['){
                len++;
            } else if(len>0 && s[i] == ']'){
                len--;
            }
        }
        return (len+1)/2;
    }
};