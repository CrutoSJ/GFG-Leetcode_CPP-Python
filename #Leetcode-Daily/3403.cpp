// #Question:-

// Link-> https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/submissions/1653925816/?envType=daily-question&envId=Invalid%20Date

// Date-> 04/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i);
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        string last = lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n - numFriends + 1));
    }
};