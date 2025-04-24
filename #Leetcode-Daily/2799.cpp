// #Question:-

// Link-> https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

// Date-> 24/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n=nums.size();
            unordered_set<int> st(nums.begin(), nums.end()); 
    
            int s = st.size();
    
            unordered_map<int,int> mp;
            int i=0, j=0;
            int res=0;
    
            while(j<n){
                mp[nums[j]]++;
    
                while(mp.size()==s){
                    res += (n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
            return res;
        }
    };