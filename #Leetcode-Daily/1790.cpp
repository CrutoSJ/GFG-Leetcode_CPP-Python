// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/mirror-tree/1

// Date-> 05/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        int numDiffs = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                numDiffs++;
                if (numDiffs > 2)
                    return false;
                else if (numDiffs == 1) {
                    firstIndexDiff = i;
                } else {
                    secondIndexDiff = i;
                }
            }
        }
        return s1[firstIndexDiff] == s2[secondIndexDiff] && s1[secondIndexDiff] == s2[firstIndexDiff];
    }
};