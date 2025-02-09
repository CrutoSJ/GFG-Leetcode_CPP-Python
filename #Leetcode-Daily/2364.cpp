// #Question:-

// Link-> https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

// Date-> 09/02/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n=nums.size();
            long long res =0;
    
            for(int i=0; i<n; i++){
                nums[i]=nums[i]-i;
            }
    
            unordered_map<int,int> mp;
            mp[nums[0]]=1;
    
            for(int j=1; j<n; j++){
                int cntOfNums = mp[nums[j]];
                int cntBefore = j;
                int badPairs = cntBefore-cntOfNums;
                res += badPairs;
                mp[nums[j]]++;
            }
        return res;
    }
};