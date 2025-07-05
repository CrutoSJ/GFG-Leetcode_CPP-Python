// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

// Date-> 05/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n =arr.size();
        int total =0;
        
        for(int i=0;i<n-1;i++){
            total =max(total , arr[i+1]+arr[i]);
        }
        
        return total;
    }
};