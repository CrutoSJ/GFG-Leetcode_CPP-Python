// #Question:-

// Link-> https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10

// Date-> 10/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxE(n,-1);

        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            maxE[i] = maxi;
        }

        int i=0, j=0;
        int res = 0;

        while(i<n && j<n){
            if(maxE[j]>=nums[i]){
                res = max(res, j-i);
                j++;
            } else{
                i++;
            }
        }
        return res;
    }
};

