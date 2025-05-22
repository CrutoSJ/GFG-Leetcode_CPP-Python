// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

// Date-> 22/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDeletions(string s) {
        int n = s.length();
        string temp = s;    
        reverse(temp.begin(), temp.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == temp[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int l = dp[n][n];
        return n-l;
        
        
    }
};