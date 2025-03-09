// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1

// Date -> 09/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int countPS(string &s) {
          int n=s.length();
          int cnt=0;
          
          for(int i=1; i<n; i++){
              int l=i-1;
              int r=i;
              while(l>=0 && r<n && s[l]==s[r]){
                  cnt++;
                  l--,r++;
              }
              l=i-1;
              r=i+1;
              while(l>=0 && r<n && s[l]==s[r]){
                  cnt++;
                  l--,r++;
              }
          }
          return cnt;
      }
  };