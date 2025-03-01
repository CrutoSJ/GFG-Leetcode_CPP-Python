// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/decode-the-string2444/1

// Date-> 01/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodedString(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ']')
                st.push(s[i]);
            else
            {
                string word;
                while (!st.empty() && st.top() != '[')
                {
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(), word.end());
                st.pop();
                string k;
                while (!st.empty() && isdigit(st.top()))
                {
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(), k.end());
                int num = stoi(k);
                string repeated;
                for (int j = 0; j < num; j++)
                {
                    repeated.append(word);
                }
                for (char c : repeated)
                    st.push(c);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};