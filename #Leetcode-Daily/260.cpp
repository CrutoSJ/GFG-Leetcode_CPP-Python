// #Question:-

// Link-> https://leetcode.com/problems/single-number-iii/

// Date -> 31/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end()); 
        int num = 0;
        int value = 0;
        for(int i=0; i<nums.size(); i++){
            num ^= nums[i];
        }
        int i= 0;
        int j= i+1;
        while(j<nums.size()){
            if(nums[i] == nums[j]){
                i=i+2;
                j=j+2;
            }
            else if(nums[i] != nums[j]){
                value = nums[i];
                break;
            }
        } 
        
        ans.push_back(value);
        ans.push_back(value^num);
        
        return ans;
        
    }
};