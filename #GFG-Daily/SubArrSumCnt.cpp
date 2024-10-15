// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1

// Date-> 15/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int> mp;
        int res = 0, sum = 0;
        
        for(auto &x : arr){
            sum += x;
            if(sum == tar){
                res++;
            }
            if(mp.find(sum-tar) != mp.end()){
                res += mp[sum-tar];
            }
            mp[sum]++;
        }
        return res;
    }
};