// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Date-> 11/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          vector<vector<pair<int,int>>>v(V);
          for(auto &x:edges){
              v[x[0]].push_back({x[2],x[1]});
              v[x[1]].push_back({x[2],x[0]});
          }
          vector<int>ans(V,INT_MAX);
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
          pq.push({0,src});
          ans[src]=0;
          while(!pq.empty()){
              auto x=pq.top();
              int i=x.second;
              int d=x.first;
              pq.pop();
              for(auto &y:v[i]){
                  if(ans[y.second]>y.first+d){
                      ans[y.second]=y.first+d;
                      pq.push({ans[y.second],y.second});
                  }
              }
          }
          return ans;
      }
  };