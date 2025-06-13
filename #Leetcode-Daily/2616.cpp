// #Question:-

// Link-> https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13

// Date-> 13/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int> &nums, int mid, int p, int n){
        int pairs = 0;
        int i = 0;

        while(i<n-1){
            if(nums[i+1] - nums[i] <= mid){
                pairs++;
                i += 2;
            } else{
                i += 1;
            }
        }

        return pairs>=p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        int l = 0;
        int h = *max_element(nums.begin(), nums.end());
        int r = INT_MAX;

        sort(nums.begin(), nums.end());

        while(l<=h){
            int mid = l + (h-l)/2;

            if(isPossible(nums, mid, p, n)){
                r = mid;
                h = mid-1;
            } else{
                l = mid+1;
            }
        }
        return r;
    }
};