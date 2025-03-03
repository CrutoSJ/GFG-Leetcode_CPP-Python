// #Question:-

// Link -> https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03

// Date -> 03/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            vector<int> res(n);
    
            int i=0, j=n-1;
            int x=0, y=n-1;
    
            while(i<n && j>=0){
                if(nums[i] < pivot){
                    res[x++] = nums[i];
                }
    
                if(nums[j] > pivot){
                    res[y--] = nums[j];
                }
    
                i++,j--;
            }
    
            while(x<=y){
                res[x++]=res[y--]=pivot;
            }
    
            return res; 
        }
    };