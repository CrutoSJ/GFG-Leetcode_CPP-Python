// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Date-> 16/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) {
          int n=dist.size();
          for(int via=0;via<n;via++)
              for(int i=0;i<n;i++)
                  for(int j=0;j<n;j++)
                      if( dist[i][via] != 1e8 and dist[via][j] != 1e8 )
                          dist[i][j]=min(dist[i][j],dist[i][via] + dist[via][j]);
          
      }
  };