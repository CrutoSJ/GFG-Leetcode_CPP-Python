// #Question:-

// Link-> https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11

// Date-> 11/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            stack<char> stk;
            int strLength = s.length();
            int partLength = part.length();
    
            for (int index = 0; index < strLength; index++) {
                stk.push(s[index]);
    
                if (stk.size() >= partLength && checkMatch(stk, part, partLength)) {
                    for (int j = 0; j < partLength; j++) {
                        stk.pop();
                    }
                }
            }
    
            string result = "";
            while (!stk.empty()) {
                result = stk.top() + result;
                stk.pop();
            }
    
            return result;
        }
    
    private:
        bool checkMatch(stack<char>& stk, string& part, int partLength) {
            stack<char> temp = stk;
    
            for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
                if (temp.top() != part[partIndex]) {
                    return false;
                }
                temp.pop();
            }
            return true;
        }
    };
    