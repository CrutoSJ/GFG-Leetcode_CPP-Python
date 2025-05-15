// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1

// Date-> 15/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        vector<int> vec(26,0);
        int res=0;
        
        for(char &ch : s){
            vec[ch - 'a']++;
            res+=vec[ch-'a'];
        }
        return res;
    }
};