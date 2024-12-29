// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1

// Date-> 29/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_map<int,bool> mp;
        vector<int> res;
        
        for(auto &x:a){
            mp[x]=true;
        }
        
        for(auto &x:b){
            if(mp[x]){
                mp[x]=false;
                res.push_back(x);
            }
        }
        return res;
    }
};