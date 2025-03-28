// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

// Date-> 28/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int activitySelection(vector<int> &start, vector<int> &finish) {
          // code here
          int n=start.size();
          vector<pair<int,int>> act;
          
          for(int i=0; i<n; i++){
              act.push_back({start[i],finish[i]});
          }
          
          sort(act.begin(), act.end(), [](const pair<int,int> &a, const pair<int,int> &b){
              return a.second<b.second;
          });
          
          int i=0,j=1;
          int cnt=1;
          
          while(j<n){
              if(act[i].second<act[j].first){
                  cnt++;
                  i=j;
                  j++;
              } else{
                  j++;
              }
          }
          return cnt;
      }
  };