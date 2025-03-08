// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

// Date -> 08/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      string longestPalindrome(string &s) {
          // code here
          int n=s.length();
          int start=0;
          int maxL=1;
      
          for(int i=n-2; i>0; i--){
              int l=i;
              int r=i+1;
              while(l>=0 && r<n && s[l]==s[r]){
                  if(r-l+1>=maxL){
                      maxL=r-l+1;
                      start=l;
                  }
                  l-=1;
                  r+=1;
              }
              l=i-1;
              r=i+1;
              while(l>=0 && r<n && s[l]==s[r]){
                  if(r-l+1>=maxL){
                      maxL=r-l+1;
                      start=l;
                  }
                  l-=1;
                  r+=1;
              }
              
          }
          return s.substr(start,maxL);
      }
  };