// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

// Date-> 21/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int missingNum(vector<int>& arr) {
          int n = arr.size();
          vector<int> vec(n+2,0);
          
          for(int &i:arr){
              vec[i]++;
          }
          
          for(int i=1; i<n+2; i++){
              if(vec[i]==0){
                  return i;
              }
          }
          
          return -1;
      }
  };