// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/word-break1352/1

// Date-> 26/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int n;
      set<string>st;
      
      bool solve(int ind, string &s, vector<int>&dp){
          if(ind==n) return 1;
          
          if(dp[ind]!=-1) return dp[ind];
          
          string tmp="";
          
          for(int i=ind; i<n; i++){
              tmp+=s[i];
              if(st.find(tmp)!=st.end()){
                  if(solve(i+1, s, dp)){
                      return dp[ind]=1;
                  }
              }
          }
          
          return dp[ind]=0;
      }
    
      bool wordBreak(string &s, vector<string> &dictionary) {
          n=s.length();
          st.insert(dictionary.begin(), dictionary.end());
          vector<int>dp(n, -1);
          
          return solve(0, s, dp);
      }
  };
