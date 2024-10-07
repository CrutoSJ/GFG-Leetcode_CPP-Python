// #Question:-

// Link-> https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07

// Date-> 07/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto &x : s){
            if(!st.empty() && ((st.top() == 'A' && x == 'B') || (st.top() == 'C' && x == 'D'))){
                st.pop();
            } else{
                st.push(x);
            }
        }

        return st.size();
    }
};