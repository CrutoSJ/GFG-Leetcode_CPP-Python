// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

// Date-> 13/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPossible(int s, vector<int> &arr, int n, int k){
        int hr = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= s){
                hr++;
                continue;
            } else{
                hr += (arr[i] + s - 1) / s;
            }
            if(hr>k) return false;
        }
        return hr<=k;
    }
    
  public:
    int kokoEat(vector<int>& arr, int k) {
        int n    = arr.size();
        int low  = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans  = high;
        
        while(low<=high){
            int mid = low + (high - low) / 2;
            
            if(isPossible(mid, arr, n, k)){
                ans = min(ans, mid);
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        
        return ans;
        
    }
};