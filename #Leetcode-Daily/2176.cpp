// #Question:-

// Link-> https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17

// Date-> 17/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int res = 0;
    
            unordered_map<int, vector<int>> idxMap;
            for(int i=0; i<n; i++){
                idxMap[nums[i]].push_back(i);
            }
    
            unordered_set<int> div;
            for(int f=1; f*f <= k; f++){
                if(k%f== 0){
                    div.insert(f);
                    div.insert(k/f);
                }
            }
    
            for(auto& [num, idx] : idxMap){
                unordered_map<int, int> factorsMap;
    
                for(int i: idx){
                    int GCD = gcd(i,k);
                    int j = k/GCD;
    
                    res += factorsMap[j];
    
                    for(int f: div){
                        if(i%f == 0){
                            factorsMap[f]++;
                        }
                    }
                }
            }
            return res;
        }
    };