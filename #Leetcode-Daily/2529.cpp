// #Question:-

// Link -> https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12

// Date -> 12/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int firstPos(vector<int> &nums, int n){
            int i=0, j=n-1;
            int idx=n;
    
            while(i<=j){
                int mid = i+(j-i)/2;
    
                if(nums[mid]<=0){
                    i=mid+1;
                } else{
                    j=mid-1;
                    idx=mid;
                }
            }
            return idx;
        }
    
        int lastNeg(vector<int> &nums, int n){
            int i=0, j=n-1;
            int idx=-1;
    
            while(i<=j){
                int mid=i+(j-i)/2;
    
                if(nums[mid]>=0){
                    j=mid-1;
                } else{
                    i=mid+1;
                    idx=mid;
                }
            }
            return idx;
        }
    
        int maximumCount(vector<int>& nums) {
            int n=nums.size();
            int posCnt=n-firstPos(nums,n);
            int negCnt=lastNeg(nums,n)+1;
    
            return max(posCnt,negCnt);
        }
    };