// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/anagram-1587115620/1

// Date-> 30/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length() != s2.length())return false;
        unordered_map<char,int> st;
        
        for(char &ch : s1){
            st[ch]++;
        }
        
        for(char &ch : s2){
            st[ch]++;
        }
        
        for(auto &x : st){
            if(x.second % 2 != 0){
                return false;
            }
        }
        
        return true;
    }
};