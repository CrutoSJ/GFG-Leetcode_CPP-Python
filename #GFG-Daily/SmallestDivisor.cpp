// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/smallest-divisor/1

// Date-> 15/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPossible(int div, int k, vector<int> &arr, int n){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += ceil((double)arr[i]/div);
            if(sum > k) return false;
        }
        return sum <= k; 
    }
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 1;
        int h = *max_element(arr.begin(), arr.end());
        int res = k;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(isPossible(mid, k, arr, n)){
                res = mid;
                h = mid-1;
            } else{
                l = mid+1;
            }
        }
        return res;
    }
};
