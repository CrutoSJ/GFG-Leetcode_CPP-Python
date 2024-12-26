// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/key-pair5616/1

// Date-> 26/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,bool> mp;
        for(auto &x:arr){
            if(mp[target-x]){
                return true;
            }
            mp[x]=true;
        }
        return false;
    }
};