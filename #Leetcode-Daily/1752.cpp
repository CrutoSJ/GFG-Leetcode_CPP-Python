// #Question:-

// Link-> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/1528564562/?envType=daily-question&envId=2025-02-02

// Date-> 02/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        
        return cnt<=1;
    }
};