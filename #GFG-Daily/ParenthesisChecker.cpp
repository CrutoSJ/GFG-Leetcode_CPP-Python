// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

// Date-> 18/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        
        for(int i=0; i<x.length(); i++){
            char ch = x[i];
            if(!st.empty() && ((ch == ')' && st.top() == '(') || 
                (ch == ']' && st.top() == '[') || 
                (ch == '}' && st.top() == '{'))){
                    st.pop();
            } else{
                st.push(ch);
            }
        }
        
        return st.size()==0;
    }

};