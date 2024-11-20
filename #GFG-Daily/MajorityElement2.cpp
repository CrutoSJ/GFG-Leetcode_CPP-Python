// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/majority-vote/1

// Date-> 20/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        map<int, int> freq;
        vector<int> res;
        
        int minFreq = n/3;
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        
        for(auto &x : freq){
            if(x.second > minFreq){
                res.push_back(x.first);
            }
        }
        
        return res;
    }
};