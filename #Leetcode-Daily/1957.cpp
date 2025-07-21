// #Question:-

// Link-> https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01

// Date-> 01/11/24 && 21/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans.reserve(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (i < 2 || !(s[i] == s[i - 1] && s[i - 1] == s[i - 2])) {
                ans += s[i];
            }
        }
        return ans;
    }
};
