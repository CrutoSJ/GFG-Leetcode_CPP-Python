// #Question:-

// Link-> https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

// Date-> 09/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openB  = 0;
        int closeB = 0;

        for(char &ch : s){
            if(ch == '('){
                openB++;
            } else{
                openB > 0 ? openB-- : closeB++;
            }
        }
        return openB + closeB;
    }
};

class Solution2 {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            } else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};