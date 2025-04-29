// #Question:-

// Link-> https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2025-04-29

// Date-> 29/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int maxE = *max_element(nums.begin(), nums.end());
            int s = nums.size();
    
            int i=0,j=0;
    
            long long res=0;
            int maxCnt=0;
    
            while(j<s){
                if(nums[j] == maxE){
                    maxCnt++;
                }
                while(maxCnt>=k){
                    res += s-j;
    
                    if(nums[i]==maxE){
                        maxCnt--;
                    }
                    i++;
                }
                j++;
            }
            return res;
        }
    };