// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/coin-piles5152/1

// Date-> 17/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> prefSum(n,0);
        prefSum[0] = arr[0];
        
        for(int i=1; i<n; i++){
            prefSum[i] = prefSum[i-1] + arr[i];
        }
        
        int res  = INT_MAX;
        int prev = 0;
        
        for(int i=0; i<n; i++){
            int idx = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            
            if(i>0){
                prev = prefSum[i-1];
            }
            
            int removeCnt = prev + prefSum[n-1] - prefSum[idx-1] - (arr[i] + k) * (n - idx);
            
            res = min(res, removeCnt);
        }
        return res;
    }
};
