// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

// Date-> 16/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int> &arr) {
        unordered_map<int,int> prefixSum;
        int n=arr.size(), sum=0, ans=0;
        for(int i=0; i<n; i++){
            sum+=arr[i]==1?1:-1;
            if(sum==0){
                ans=i+1;
            }
            if(prefixSum.find(sum) != prefixSum.end()){
                ans=max(ans,i-prefixSum[sum]);
            } else{
                prefixSum[sum]=i;
            }
        }
        return ans;
    }
};