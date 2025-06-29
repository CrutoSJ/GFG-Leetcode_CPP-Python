// #Question:-

// Link-> https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/?envType=daily-question&envId=2025-06-29

// Date-> 29/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>pow1(n,1);
        for(int i=1;i<n;i++){
            pow1[i]=(pow1[i-1]*2)%mod;
        }
        int i=0,j=n-1,result=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                result = (result + pow1[j-i]) % mod;
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
};