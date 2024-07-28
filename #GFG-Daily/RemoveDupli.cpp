// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/remove-duplicates3034/1

// Date-> 28/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string removeDups(string str) {
        string ans="";
        unordered_map<char,int>mp;
        
        for(int i=0; i<str.length(); i++){
            if(mp[str[i]] == 0){
                ans.push_back(str[i]);
                mp[str[i]]++;
            }
        }
        return ans;
    }
};