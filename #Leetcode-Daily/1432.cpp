// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/smallest-divisor/1

// Date-> 15/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // For max: Replace the first digit that's not 9 with 9
        string maxS = s;
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char& c : maxS)
                if (c == toReplaceMax) c = '9';
        }

        // For min: If the first digit is not 1, replace all of that digit with 1
        // Otherwise, replace the first digit that's not 0 or 1 with 0
        string minS = s;
        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char& c : minS)
                if (c == toReplaceMin) c = '1';
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (char& c : minS)
                    if (c == toReplaceMin) c = '0';
            }
        }

        return stoi(maxS) - stoi(minS);
    }
};
