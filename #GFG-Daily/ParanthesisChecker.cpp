// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

// Date-> 21/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBalanced(string &s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (!st.empty() && ((ch == ')' && st.top() == '(') ||
                                (ch == ']' && st.top() == '[') ||
                                (ch == '}' && st.top() == '{')))
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        return st.size() == 0;
    }
};