// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1

// Date-> 10/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mp;
        int res = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
            } else{
                int len = i-mp[arr[i]];
                res = max(res, len);
            }
        }
        return res;
    }
};