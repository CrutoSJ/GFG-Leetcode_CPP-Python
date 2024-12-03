// #Question:-

// Date-> 03/12/24

// Link-> https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        string res = "";
        for(int i=0; i<s.length(); i++){
            if(j<spaces.size() && i == spaces[j]){
                res += ' ';
                j++;
            }
            res += s[i];
        }
        return res;
    }
};