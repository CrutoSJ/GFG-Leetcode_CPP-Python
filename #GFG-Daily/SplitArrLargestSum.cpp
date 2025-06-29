// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1

// Date-> 29/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPossible(int thold, vector<int> &arr, int k){
        int sum = 0;
        int cnt = 1;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(sum + arr[i] <= thold){
                sum += arr[i];
            } else{
                sum = arr[i];
                cnt++;
            }
        }
        
        return cnt<=k;
    }
    
  public:
    int splitArray(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);
        int res = INT_MAX;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(isPossible(mid, arr, k)){
                h = mid-1;
                res = mid;
            } else{
                l = mid+1;
            }
        }
        
        return res;
    }
};