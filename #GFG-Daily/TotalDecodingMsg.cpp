// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

// Date-> 23/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      int dp[1001];
      int solve(string &digits, int idx){
          if(idx>=n){
              return 1;
          }
          
          if(dp[idx] != -1){
              return dp[idx];
          }
          
          int curr=digits[idx]-'0';
          if(curr == 0)return 0;
          
          int one=solve(digits, idx+1);
          int two=0;
          
          if(idx+1<n){
              curr=curr*10+(digits[idx+1]-'0');
              if(curr<=26){
                  two=solve(digits,idx+2);
              }
          }
          return dp[idx] = one+two;
      }
      int countWays(string &digits) {
          n=digits.size();
          memset(dp, -1, sizeof(dp));
          return solve(digits, 0);
          
      }
  };