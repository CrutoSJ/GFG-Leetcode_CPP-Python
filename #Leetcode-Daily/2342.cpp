// #Question:-

// Link-> https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/?envType=daily-question&envId=2025-02-12

// Date-> 12/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int getSum(int num){
            int ans=0;
            while(num>0){
                ans+=num%10;
                num/=10;
            }
            return ans;
        }
        int maximumSum(vector<int>& nums) {
            unordered_map<int,int> mp;
            int n = nums.size();
            int res=-1;
    
            for(int i=0; i<n; i++){
                int digitSum = getSum(nums[i]);
    
                if(mp.count(digitSum)){
                    res = max(res, nums[i]+mp[digitSum]);
                }
    
                mp[digitSum] = max(nums[i], mp[digitSum]);
            }
            return res;
        }
    };