// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1

// Date-> 31/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maxPartitions(string &s) {
          int n = s.length();
          unordered_map<char,int> map;
          
          for(int i=0; i<n; i++){
              map[s[i]] = i;
          }
          int count = 0;
          int i = 0;
          
          while(i < n){
              int last = map[s[i]];
              int j = i;
              
              while(j < last){
                  last = max(last,map[s[j]]);
                  j++;
              }
              count++;
              i = j+1;
          }
          return count;
      }
  };