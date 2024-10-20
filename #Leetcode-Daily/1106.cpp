// #Question:-

// Link-> https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20

// Date-> 20/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (char currChar : expression) {
            if (currChar == ',' || currChar == '(')
                continue; 

            if (currChar == 't' || currChar == 'f' || currChar == '!' ||
                currChar == '&' || currChar == '|') {
                stk.push(currChar);
            }
            else if (currChar == ')') {
                bool hasTrue = false, hasFalse = false;

                while (stk.top() != '!' && stk.top() != '&' && stk.top() != '|') {
                    char topValue = stk.top();
                    stk.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }

                char op = stk.top();
                stk.pop();
                if (op == '!') {
                    stk.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    stk.push(hasFalse ? 'f' : 't');
                } else {
                    stk.push(hasTrue ? 't' : 'f');
                }
            }
        }

        return stk.top() == 't';
    }
};