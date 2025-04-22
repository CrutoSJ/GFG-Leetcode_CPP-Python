// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-unique-number/1

// Date-> 22/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findUnique(vector<int> &arr) {
          int x=0;
          for(int i=0; i<arr.size(); i++){
              x^=arr[i];
          }
          return x;
          
      }
  };