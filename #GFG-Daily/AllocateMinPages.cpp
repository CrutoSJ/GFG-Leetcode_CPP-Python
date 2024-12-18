// #Question:-

// Date-> 18/12/24

// Link-> https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        return solve(arr, arr.size(), k);
    }
    
    int isP(int maxi, vector<int> &arr, int n, int m){
        int cnt=1;
        int sum=0;
        for(int i=0; i<n; i++){
            if(sum+arr[i]<=maxi){
                sum+=arr[i];
            }else{
                cnt++;
                sum=arr[i];
            }
        }
        return cnt;
    }
    
    int solve(vector<int> &A, int N, int M) 
    {
        if(N<M) return -1;
        int hi=A[0];
        int lo=A[0];
        for(int i=1; i<N; i++){
            hi+=A[i];
            lo=max(lo, A[i]);
        }
        
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isP(mid, A, N, M)>M){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return lo;
    }
};