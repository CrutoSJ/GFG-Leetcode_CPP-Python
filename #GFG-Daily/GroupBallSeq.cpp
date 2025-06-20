// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1

// Date-> 20/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n%k != 0) return false;
        
        map<int,int> mp;
        
        for(auto & num : arr){
            mp[num]++;
        }
        
        for(auto &it : mp){
            int val  = it.first;
            int freq = it.second;
            
            if(freq==0){
                continue;
            }
            
            for(int i=1; i<k; i++){
                int nextVal = val+i;
                if(mp[nextVal] < freq){
                    return false;
                }
                mp[nextVal] -= freq;
            }
        }
        return true;
    }
};
