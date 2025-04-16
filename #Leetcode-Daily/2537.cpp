// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Date-> 16/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            int i = 0;
            int j = 0;
            int pairs = 0;
            unordered_map<int,int> mp;
            long long res=0;
    
            while(j<n){
                pairs += mp[nums[j]];
                mp[nums[j]]++;
    
                while(pairs>=k){
                    res+=(n-j);
                    mp[nums[i]]--;
                    pairs-=mp[nums[i]];
                    i++;
                }
                j++;
            }
            return res;
        }
    };