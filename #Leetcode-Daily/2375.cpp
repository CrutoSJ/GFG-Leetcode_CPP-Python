// #Question:-

// Link-> https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18

// Date-> 18/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string smallestNumber(string pattern) {
            string result;
            stack<int> numStack;
    
            for (int index = 0; index <= pattern.size(); index++) {
                numStack.push(index + 1);
    
                if (index == pattern.size() || pattern[index] == 'I') {
                    while (!numStack.empty()) {
                        result += to_string(numStack.top());
                        numStack.pop();
                    }
                }
            }
    
            return result;
        }
    };