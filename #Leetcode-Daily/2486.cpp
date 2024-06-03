// #Question:-

// Link-> https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

//Date -> 03/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = t.length();
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length()){
            if( s[i] == t[j]){
                ans--;
                i++;
                j++;
            }
            if(s[i]!=t[j]){
                i++;
            }
        }
        
        return ans;
    }
};