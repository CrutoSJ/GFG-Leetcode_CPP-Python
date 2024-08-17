// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

// Date-> 17/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        int n = nums.size();
        long long int val = 1;
        int zeroCnt = 0;
        pair<bool,int> flag = {false, -1};
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                flag.first = true;
                flag.second = i;
                zeroCnt++;
                continue;
            } else{
                val *= nums[i];
            }
        }
        
        if(flag.first){
            for(int i=0; i<n; i++){
                if(zeroCnt == 1 && i == flag.second){
                    nums[i] = val;
                    continue;
                }
                nums[i] = 0;
            }
        } else{
            for(int i=0; i<n; i++){
                nums[i] = val/nums[i];
            }
        }
        return nums;
    }
};