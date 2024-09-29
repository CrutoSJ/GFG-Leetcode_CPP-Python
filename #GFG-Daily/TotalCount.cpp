// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/total-count2415/1

// Date-> 29/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int i=0; i<arr.size(); i++){
            mp[k] += arr[i]/k;
            if((arr[i] % k) != 0){
                mp[(arr[i]%k)]++;
            }
        }
        
        int res = 0;
        for(auto &i : mp){
            res += i.second;
        }
        
        return res;
    }
};