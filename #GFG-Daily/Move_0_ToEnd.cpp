// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

// Date-> 16/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int idx = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                arr[idx++] = arr[i];
            }
        }
        
        while(idx<n){
            arr[idx++] = 0;
        }
    }
};