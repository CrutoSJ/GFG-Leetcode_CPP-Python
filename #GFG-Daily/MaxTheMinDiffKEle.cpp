// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1

// Date-> 21/08/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int isPoss(vector<int>&arr,int mid){
        int last=arr[0];
        int k=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last<mid){
                continue;
            } else{
                k+=1;
                last=arr[i];
            }
        }
        return k;
  }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans;
        int l=0,h=arr[n-1]-arr[0];
        while(l<=h){
            int mid=(l+h)/2;
            int ch=isPoss(arr,mid);
            if(ch>=k){
                ans=mid;
                l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        return ans;
    }
};
