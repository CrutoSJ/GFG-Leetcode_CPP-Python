// #Question:-

// Link -> https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15

// Date -> 15/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        bool isPossible(vector<int> &nums, int k, int mid){
            int house=0;
            for(int i=0; i<n; i++){
                if(nums[i]<=mid){
                    house++;
                    i++;
                }
            }
            return house>=k;
        }
        int minCapability(vector<int>& nums, int k) {
            n=nums.size();
    
            int l=*min_element(nums.begin(), nums.end());
            int r=*max_element(nums.begin(), nums.end());
    
            int res=r;
    
            while(l<=r){
                int mid=l+(r-l)/2;
    
                if(isPossible(nums, k, mid)){
                    res=mid;
                    r=mid-1;
                } else{
                    l=mid+1;
                }
            }
            return res;
        }
    };