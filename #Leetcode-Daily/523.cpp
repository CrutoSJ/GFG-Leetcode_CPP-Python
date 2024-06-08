// #Question:-

// Link-> https://leetcode.com/problems/continuous-subarray-sum/

//Date -> 08/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int modSum = 0;
        unordered_map<int,int>modSeen;
        modSeen[0] = -1;
        
        for(int i=0; i<nums.size(); i++){
            modSum = (modSum+nums[i])%k;
            if(modSeen.find(modSum) != modSeen.end()){
                if(i-modSeen[modSum] > 1) return true;
            } else{
                modSeen[modSum] = i;
            }
        }
        return false;
    }
};