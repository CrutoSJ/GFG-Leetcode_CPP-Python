// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

// Date-> 28/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int evaluate(vector<string>& arr) {
          stack<int> st;
          for(auto &i : arr){
              if(i == "+" || i == "-" || i == "*" || i == "/"){
                  int b = st.top();
                  st.pop();
                  int a = st.top();
                  st.pop();
                  int res;
                  
                  if(i == "+"){
                      res = a+b;
                  } else if(i == "-"){
                      res = a-b;
                  } else if(i == "*"){
                      res = a*b;
                  } else if(i == "/"){
                      res = a/b;
                  }
                  
                  st.push(res);
              } else{
                  st.push(stoi(i));
              }
          }
          return st.top();
      }
  };