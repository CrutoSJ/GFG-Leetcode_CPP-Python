// #Question:-

// #Link-> https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

//Date -> 27/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int isPossible(vector<int>&nums, int mid, int s, int e){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=mid){
                count++;
            }
        }
        
        return count;
    }
    
public:
    int specialArray(vector<int>& nums) {
        int s = 1;
        int e = nums.size();
        int ans = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            int value = isPossible(nums,mid,s,e); 
            
            if(value == mid){
                ans = mid;
                return ans;
            }
            
            else if(value > mid){
                s = mid+1;
            }
            
            else{
                e=mid-1;
            }
        }
        
        return ans;
    }
};