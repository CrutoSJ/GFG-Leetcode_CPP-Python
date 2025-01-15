// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// Date-> 15/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size(), sum=0, ans=0;
        unordered_map<int,int> prefixSum;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==k){
                ans=i+1;
            } else if(prefixSum.find(sum-k)!=prefixSum.end()){
                ans=max(ans,i-prefixSum[sum-k]);
            }
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        return ans;
    }
};