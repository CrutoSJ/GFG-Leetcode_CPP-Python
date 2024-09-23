// #Question:-

// Link-> https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23

// Date-> 23/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s, unordered_set<string> &st, int i, int n, vector<int> &dp){
        if(i>=n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ans = 1 + solve(s, st, i+1, n, dp);

        for(int j=i; j<n; j++){
            string word = s.substr(i, j-i+1);
            if(st.find(word) != st.end()){
                ans = min(ans, solve(s, st, j+1, n, dp));
            }
        }

        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();

        vector<int> dp(n+1, -1);

        unordered_set<string> st;

        for(auto &x : dictionary){
            st.insert(x);
        }

        return solve(s, st, 0, n, dp);
    }
};