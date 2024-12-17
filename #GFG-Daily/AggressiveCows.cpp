// #Question:-

// Date-> 17/12/24

// Link-> https://www.geeksforgeeks.org/problems/aggressive-cows/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k, int mid, int n){
        int cows=1, prev=stalls[0];
        for(int i=1; i<n; i++){
            if(stalls[i]-prev>=mid){
                cows++;
                prev=stalls[i];
            }
        }
        return cows>=k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n=stalls.size(), low=0, high=stalls[n-1]-stalls[0], mid, ans=0;
        
        while(low<=high){
            mid = low + (high-low)/2;
            if(isPossible(stalls,k,mid,n)){
                ans=max(mid,ans);
                low=mid+1;
            } else{
                high=mid-1;
            }
        }
        return ans;
    }
};