// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1

// Date-> 08/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findMissing(vector<int> &arr) {
          unordered_map<int,int> mp;
          int n=arr.size();
          
          for(int i=0;i<n-1;i++)
          {
              mp[arr[i+1]-arr[i]]++;
          }
          
          int d=-1;
          int sz=-1;
          for(auto it:mp)
          {
              if(it.second>sz)
              {
                  sz=it.second;
                  d=it.first;
              }
          }
          
          for(int i=0;i<n-1;i++)
          {
              if(arr[i]+d != arr[i+1])
              {
                  return arr[i]+d;
              }
          }
          
          return arr[n-1]+d;
          
      }
  };