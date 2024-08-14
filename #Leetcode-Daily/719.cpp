// #Question:-

// Link-> https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14

// Date-> 14/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findPairs(int i, int j, int mid, vector<int> &nums){
        int pairs = 0;
        while(j<nums.size()){
            while(nums[j]-nums[i] > mid){
                i++;
            }
            pairs += (j-i);
            j++;
        }
        return pairs;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        int s=0, e=nums[n-1] - nums[0];
        int result = 0;

        while(s<=e){
            int mid = s + (e-s)/2;
            int pairCnt = findPairs(0,1, mid, nums);

            if(pairCnt >= k){
                result = mid;
                e=mid-1;
            } else{
                s=mid+1;
            }
        }

        return result;
    }
};