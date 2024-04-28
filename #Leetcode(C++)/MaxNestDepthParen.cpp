// #Question:-

// Link-> https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi = 0;
        for(char c : s){
            if(c =='('){
                st.push(c);
            } 
            else if (c == ')'){
                maxi = max((int)st.size(),maxi);
                st.pop();
            }
        }
        
        return maxi;
    }
};

