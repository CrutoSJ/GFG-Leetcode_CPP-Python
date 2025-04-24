// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

// Date-> 24/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int getSingle(vector<int> &arr) {
          unordered_map<int,int> mp;
          
          for(int &i:arr){
              mp[i]++;
          }
          
          for(auto &x:mp){
              if(x.second == 1){
                  return x.first;
              }
          }
          return 0;
      }
  };