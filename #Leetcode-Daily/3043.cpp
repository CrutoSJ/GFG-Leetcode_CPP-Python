// #Question:-

// Link-> https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

// Date-> 24/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> mp;
        int res = 0;

        for(int i=0; i<arr1.size(); i++){
            string a  = to_string(arr1[i]);
            string ch = "";
            for(auto &x:a){
                ch += x;
                mp.insert(ch);
            }
        }

        for(int i=0; i<arr2.size(); i++){
            string a  = to_string(arr2[i]);
            string ch = "";
            for(auto &x:a){
                ch += x;
                if(mp.find(ch) != mp.end()){
                    int size = ch.length();
                    res = max(res, size);
                }
            }
        }

        return res;
    }
};