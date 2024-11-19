// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/next-permutation5226/1

// Date-> 19/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int idx = -1;
        
        for(int i=n-1; i>0; i--){
            if(arr[i-1]<arr[i]){
                idx = i-1;
                break;
            }
        }
        
        if(idx==-1){
            reverse(arr.begin(), arr.end());
            return ;
        }
        
        for(int i=n-1; i>idx; i--){
            if(arr[i]>arr[idx]){
                swap(arr[i], arr[idx]);
                break;
            }
        }
        reverse(arr.begin()+idx+1, arr.end());
    }
};