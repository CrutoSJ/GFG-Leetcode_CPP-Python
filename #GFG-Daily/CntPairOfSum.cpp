// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1

// Date-> 27/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto &x:arr){
            if(mp[target-x]){
                cnt+=mp[target-x];
            }
            mp[x]++;
        }
        return cnt;
    }
};