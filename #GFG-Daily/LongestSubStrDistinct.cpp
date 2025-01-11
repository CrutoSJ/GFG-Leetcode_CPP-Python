// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

// Date-> 11/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestUniqueSubstr(string &s) {
        int i=0, j=0, n=s.size(), ans=0;
        vector<bool> cnt(26,false);
        
        while(j<n){
            int temp=s[j]-'a';
            while(cnt[temp]){
                cnt[s[i]-'a']=false;
                i++;
            }
            ans=max(ans, j-i+1);
            cnt[temp]=true;
            j++;
        }
        return ans;
    }
};