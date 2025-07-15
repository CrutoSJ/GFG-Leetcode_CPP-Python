// #Question:-

// Link-> https://leetcode.com/problems/valid-word/submissions/1698892652/?envType=daily-question&envId=2025-07-15

// Date-> 15/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        
        bool hasVowel = false;
        bool hasCons = false;

        for (char ch : word) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasCons = true;
                }
            } else if (!isdigit(ch)) {
                return false;
            }
        }

        return (hasVowel && hasCons);
    }
};
