// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1

// Date-> 23/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> singleNum(vector<int>& arr) {
          unordered_set<int> st;
          
          for(int &i:arr){
              if(st.find(i) != st.end()){
                  st.erase(i);
              } else{
                  st.insert(i);
              }
          }
          
          vector<int> res;
          
          for(auto &i:st){
              res.push_back(i);
          }
          
          if(res[0]>res[1]){
              swap(res[0],res[1]);
          }
          
          return res;
      }
  };