// #Question:-

// Link-> https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20

// Date-> 20/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int> mp;
            int cnt=0;
    
            for(int &i : answers){
                mp[i]++;
            }
    
            for(auto &it : mp){
                int x = it.first;
                int value = it.second;
    
                int grpSize = x+1;
                int grp = ceil((double)value/grpSize);
    
                cnt += grp * (grpSize);
            }
    
            return cnt;
        }
    };