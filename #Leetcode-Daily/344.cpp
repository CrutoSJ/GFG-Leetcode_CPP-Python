// #Question:-

// Link-> https://leetcode.com/problems/reverse-string/

//Date -> 02/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int r=s.size()-1;
        int l=0;
        while(l<=r){
            swap(s[r],s[l]);
            l++;
            r--;
        }
    }
};