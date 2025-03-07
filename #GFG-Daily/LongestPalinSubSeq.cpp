// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

// Date -> 07/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int dp[1001][1001];
      
      int solve(int i, int j, string &s){
          
          if(i==j){
              return 1;
          }
          
          if(i>j){
              return 0;
          }
          
          if(dp[i][j] != -1){
              return dp[i][j];
          }
          
          if(s[i]==s[j]){
              return dp[i][j] = 2+solve(i+1,j-1,s);
          } else{
              return dp[i][j] = max(solve(i+1,j,s), solve(i,j-1,s));
          }
      }
      
      int longestPalinSubseq(string &s) {
          n = s.length();
          memset(dp, -1, sizeof(dp));
          return solve(0,n-1,s);
      
      }
  };