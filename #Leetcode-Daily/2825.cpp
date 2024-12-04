// #Question:-

// Link-> https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04

// Date-> 04/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        for (int str1Index = 0; str1Index < lengthStr1 && str2Index < lengthStr2; ++str1Index) {
            if (str1[str1Index] == str2[str2Index] ||
                (str1[str1Index] + 1 == str2[str2Index]) ||
                (str1[str1Index] - 25 == str2[str2Index])) {
                str2Index++;
            }
        }
        return str2Index == lengthStr2;
    }
};