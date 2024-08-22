// #Question:-

// Link-> https://leetcode.com/problems/strange-printer/description/?envType=daily-question&envId=2024-08-21

// Date-> 21/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[101][101];
    int solve(int l, int r, string &s){
        if(l==r){
            return 1;
        }
        if(l>r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int i = l+1;
        while(i<=r && s[i] == s[l]){
            i++;
        }
        if(i>r){
            return 1;
        }

        int basic = 1 + solve(i, r, s);
        int lalach = INT_MAX;

        for(int j=i; j<=r; j++){
            if(s[j] == s[l]){
                int ans = solve(i, j-1, s) + solve(j ,r, s);
                lalach = min(lalach, ans);
            }
        }

        return dp[l][r] = min(basic, lalach);

    }
    int strangePrinter(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, s);
    }
};