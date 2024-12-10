// #Question:-

// Link-> https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10

// Date-> 10/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> count;
        int substringLength = 0;
        for (int start = 0; start < s.length(); start++) {
            char character = s[start];
            substringLength = 0;
            for (int end = start; end < s.length(); end++) {
                if (character == s[end]) {
                    substringLength++;
                    count[{character, substringLength}]++;
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto i : count) {
            int len = i.first.second;
            if (i.second >= 3 && len > ans) ans = len;
        }
        if (ans == 0) return -1;
        return ans;
    }
};