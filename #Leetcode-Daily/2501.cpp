// #Question:-

// Link-> https://leetcode.com/problems/longest-square-streak-in-an-array/description/

// Date-> 28/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            int len = 1, curr = nums[i];
            int s = i+1, e = n-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(curr == sqrt(nums[mid])){
                    len++;
                    curr = nums[mid];
                    s=mid+1;
                    e=n-1;
                } else if(curr>sqrt(nums[mid])){
                    s=mid+1;
                } else {
                    e=mid-1;
                }
            }
            if(len>=2){
                maxLen = max(maxLen,len);
            }
        }
        return maxLen == 0 ? -1 : maxLen;
    }
};