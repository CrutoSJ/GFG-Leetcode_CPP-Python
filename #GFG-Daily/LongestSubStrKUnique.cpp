// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// Date-> 03/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int>mp;
        int n=s.length();
        int cnt=0;
        int left=0;
        int maxi=INT_MIN;
        for(int right=0;right<n;right++)
        {
            mp[s[right]]++;
            if(mp.size()==k)
            {
                maxi=max(maxi,right-left+1);
            }
            while(mp.size()>k)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return (maxi==INT_MIN)?-1:maxi;
    }
};