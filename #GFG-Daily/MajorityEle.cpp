// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

// Date-> 25/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          int n=arr.size();
          unordered_map<int,int> mp;
          
          for(int i=0; i<n; i++){
              mp[arr[i]]++;
          }
          
          for(auto &x:mp){
              if(x.second > (n/2)){
                  return x.first;
              }
          }
          return -1;
      }
  };