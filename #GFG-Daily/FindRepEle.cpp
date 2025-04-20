// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1

// Date-> 20/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findDuplicate(vector<int>& arr) {
          unordered_set<int> st;
          
          for(auto &i : arr){
              if(st.find(i) != st.end()){
                  return i;
              }
              st.insert(i);
          }
          
          return 0;
          
      }
  };