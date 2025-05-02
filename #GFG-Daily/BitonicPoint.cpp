// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

// Date-> 02/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          int s = arr.size();
          int res = arr[0];
          
          for(int i=1; i<s; i++){
              if(arr[i]>res){
                  res=arr[i];
              }
          }
          return res;
          
      }
  };