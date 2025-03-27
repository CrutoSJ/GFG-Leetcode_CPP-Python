// #Question:-

// Link-> https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

// Date-> 27/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> mp1, mp2;
            int n=nums.size();
    
            for(auto & num : nums){
                mp2[num]++;
            }
    
            for(int idx=0; idx<n; idx++){
                int num=nums[idx];
                mp2[num]--;
                mp1[num]++;
    
                if(mp1[num]*2 > idx+1 && mp2[num]*2 > n-idx-1){
                    return idx;
                }
            }
            return -1;
        }
    };