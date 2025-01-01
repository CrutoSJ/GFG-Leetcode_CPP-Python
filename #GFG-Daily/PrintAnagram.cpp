// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/print-anagrams-together/1

// Date-> 01/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        
        for(auto &x: arr){
            string temp = x;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(x);
        }
        
        for(auto &x:mp){
            res.push_back(x.second);
        }
        
        return res;
    }
};