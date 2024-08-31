// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

// Date-> 31/08/24

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> smaller(n);
        int mini = arr[0];
        for(int i=0; i<n; i++){
            if(arr[i]<mini){
                mini = arr[i];
            }
            smaller[i] = mini;
        }
        
        vector<int> larger(n);
        int maxi = arr[n-1];
        for(int i=n-1; i>=0; i--){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
            larger[i] = maxi;
        }
        
        for(int i=0; i<n; i++){
            if(smaller[i]<arr[i] && arr[i]<larger[i]){
                return {smaller[i], arr[i], larger[i]};
            }
        }
        
        return {};
    }
};