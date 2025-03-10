// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/edit-distance3702/1

// Date -> 10/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

// Recurssion + Memoization 1 (0->end) :-


class Solution {
    public:
      // Function to compute the edit distance between two strings
      int dp[1001][1001];
      int solve(string &s1, string &s2, int i, int j){
          if(i==s1.length()){
              return s2.length()-j;
          } else if(j==s2.length()){
              return s1.length()-i;
          }
          
          if(dp[i][j] != -1){
              return dp[i][j];
          }
          
          if(s1[i]==s2[j]){
              return dp[i][j] = solve(s1,s2,i+1,j+1);
          }
          
          int ins = 1+solve(s1,s2,i,j+1);
          int dlt = 1+solve(s1,s2,i+1,j);
          int rep = 1+solve(s1,s2,i+1,j+1);
          
          return dp[i][j] = min({ins,dlt,rep});
      }
      int editDistance(string& s1, string& s2) {
          memset(dp, -1, sizeof(dp));
          return solve(s1,s2,0,0);
      }
  };

// Recursion + Memoization (end->0) :-


class Solution {
    public:
      // Function to compute the edit distance between two strings
      int m, n;
      int dp[1001][1001];
      int solve(string &s1, string &s2, int m, int n){
          if(m==0 || n==0){
              return m+n;
          }
          
          if(dp[m][n] != -1){
              return dp[m][n];
          }
          
          if(s1[m-1]==s2[n-1]){
              return dp[m][n] = solve(s1,s2,m-1,n-1);
          }
          
          int ins = 1+solve(s1,s2,m,n-1);
          int dlt = 1+solve(s1,s2,m-1,n);
          int rep = 1+solve(s1,s2,m-1,n-1);
          
          return dp[m][n] = min({ins,dlt,rep});
      }
      int editDistance(string& s1, string& s2) {
          m = s1.length();
          n = s2.length();
          memset(dp, -1, sizeof(dp));
          return solve(s1,s2,m,n);
      }
  };


// Bottom - Up Dp :-


class Solution {
    public:
      // Function to compute the edit distance between two strings
      int editDistance(string& s1, string& s2) {
          int m = s1.length();
          int n = s2.length();
          
          vector<vector<int>> dp(m+1 ,vector<int>(n+1));
          
          for(int i=0; i<=m; i++){
              for(int j=0; j<=n; j++){
                  if(i==0 || j==0){
                      dp[i][j] = i+j;
                  } else if(s1[i-1]==s2[j-1]){
                      dp[i][j] = dp[i-1][j-1];
                  } else{
                      dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                  }
              }
          }
          return dp[m][n];
      }
  };