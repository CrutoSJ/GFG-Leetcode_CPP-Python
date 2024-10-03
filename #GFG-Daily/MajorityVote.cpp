// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/majority-vote/1

// Date-> 03/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        unordered_map<int,int> mp;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        set<int> st;
        
        for(auto it:mp){
            if(it.second>n/3) st.insert(it.first);
        }
        
        if(st.size()==0) return {-1};
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};