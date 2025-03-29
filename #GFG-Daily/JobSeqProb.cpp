// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

// Date-> 29/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          vector<pair<int,int>> v;
          int n = deadline.size();
          int maxProfit = 0 , maxJobs = 0;
          for(int i = 0 ; i < n ; i ++)
              v.push_back({profit[i],deadline[i]});
          sort(v.begin(),v.end(),[](pair<int,int> &a, pair<int,int> &b){
              return a.first > b.first;
          });
          vector<int> hashArray(*max_element(deadline.begin(),deadline.end()) + 1,-1);
          
          for(int i = 0 ; i < n ; i++){
              int k = v[i].second;
              while(true){
                  if(hashArray[k] == -1){
                      hashArray[k] = i;
                      maxProfit += v[i].first;
                      maxJobs++;
                      break;
                  } else {
                      k--;
                      if(k == 0)
                          break;
                  }
              }
          }
          return {maxJobs,maxProfit};
      }
  };