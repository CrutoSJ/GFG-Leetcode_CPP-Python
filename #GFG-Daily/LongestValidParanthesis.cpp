// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

// Date-> 22/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(string &str)
    {
        int n = str.length();
        stack<int> st;
        st.push(-1);

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    result = max(result, i - st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }

        return result;
    }
};