// #Question:-

// Link-> https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/?envType=daily-question&envId=2024-11-16

// Date-> 16/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1, -1);
        int cnt = 1;

        for(int i=1; i<k; i++){
            if(nums[i] == nums[i-1]+1){
                cnt++;
            } else{
                cnt = 1;
            }
        }

        if(cnt == k){
            res[0] = nums[k-1];
        }

        int i=1;
        int j=k;

        while(j<n){
            if(nums[j] == nums[j-1]+1){
                cnt++;
            } else{
                cnt = 1;
            }

            if(cnt >= k){
                res[i] = nums[j];
            }

            i++;
            j++;
        }

        return res;
    }
};