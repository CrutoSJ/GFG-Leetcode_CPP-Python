// #Question:-

// Link-> https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Date-> 11/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int>st;
        vector<int>map(n);
        
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            } else if(s[i] == ')'){
                int len = st.top();
                st.pop();
                map[i] = len;
                map[len] = i;
            }
        }
        
        string ans="";
        int flag = 1;
        for(int i=0; i<n; i+=flag){
            if(s[i] == '(' || s[i] == ')'){
                i = map[i];
                flag = -flag;
            } else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};