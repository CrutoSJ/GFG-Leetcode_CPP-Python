// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Date-> 27/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          int n=arr.size();
          int cnt=0, stCnt=0;
          
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          
          int i=0, j=0;
          
          while(i<n){
              if(arr[i]<=dep[j]){
                  cnt++,i++;
              } else{
                  cnt--,j++;
              }
              stCnt = max(stCnt,cnt);
          }
          return stCnt;
      }
  };