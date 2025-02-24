// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

// Date-> 24/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          int n=arr.size();
          vector<int> ans(n,1);
          stack<pair<int,int>> st;
          for(int i=0; i<n; i++){
              while(!st.empty() && arr[i]>=st.top().first){
                  st.pop();
              }
              if(st.empty()){
                  ans[i]=i+1;
              } else{
                  ans[i]=i-st.top().second;
              }
              st.push({arr[i],i});
          }
          return ans;
      }
  };