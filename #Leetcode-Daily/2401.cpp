// #Question:-

// Link-> https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18

// Date-> 18/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n=nums.size();
            int i=0,j=0;
            int res=1;
            int mask=0;
    
            while(j<n){
                while((mask&nums[j])!=0){//shrinking the window
                    mask = (mask^nums[i]);
                    i++;
                }
    
                res  = max(res,j-i+1);
                mask = (mask|nums[j]);
                j++;
            }
            return res;
        }
    };