// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

// Date-> 14/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0;
        
        for(int i=0; i<n; ){
            while(i<n && pq.size()<=k){
                pq.push(arr[i++]);
            }
            
            arr[idx++] = pq.top();
            pq.pop();
        }
        
        while (!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};