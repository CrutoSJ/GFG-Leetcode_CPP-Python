// #Question:-

// Link-> https://leetcode.com/problems/maximum-score-from-removing-substrings/

// Date-> 12/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMaxGain(stack<char>& st, string s, int x, int y, bool isBA_AB) {
        int sum = 0;
        char fromChar = isBA_AB ? 'b' : 'a';
        char toChar = isBA_AB ? 'a' : 'b';
        int gainFrom = isBA_AB ? y : x;
        int gainTo = isBA_AB ? x : y;
        
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && st.top() == fromChar && s[i] == toChar) {
                sum += gainFrom;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        string reversedString;
        while (!st.empty()) {
            reversedString.push_back(st.top());
            st.pop();
        }
        
        for (int i = 0; i < reversedString.length(); i++) {
            if (!st.empty() && st.top() == fromChar && reversedString[i] == toChar) {
                sum += gainTo;
                st.pop();
            } else {
                st.push(reversedString[i]);
            }
        }
        
        return sum;
    }

public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int sum = 0;
        
        if (y > x) {
            sum = findMaxGain(st, s, x, y, true); 
        } else {
            sum = findMaxGain(st, s, x, y, false); 
        }
        
        return sum;
    }
};
