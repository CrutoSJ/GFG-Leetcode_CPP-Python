// #Solution:-

// Link-> https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04

// Date-> 04/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        string comp = "";
        int i=0;

        while(i<n){
            int cnt = 0;
            char ch = word[i];

            while(i<n && cnt<9 && word[i] == ch){
                cnt++;
                i++;
            }
            comp += to_string(cnt) + ch;
        }
        return comp;
    }
};