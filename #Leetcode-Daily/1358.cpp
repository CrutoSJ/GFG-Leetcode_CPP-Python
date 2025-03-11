// #Question:-

// Link -> https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11

// Date -> 11/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n=s.length();
            unordered_map<char,int> mp;
            int i=0, j=0;
            int res=0;
    
            while(j<n){
                char ch=s[j];
                mp[ch]++;
    
                while(mp.size()==3){
                    res+=n-j;
                    char ch=s[i];
                    mp[ch]--;
                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                    i++;
                }
                j++;
            }
            return res;
        }
    };