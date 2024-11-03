// #Question:-

// Link-> https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2024-11-03

// Date-> 03/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n =s.length();
        int m =goal.length();

        if(m!=n){
            return false;
        }

        if((s+s).find(goal) != string::npos){
            return true;
        }
        return false;
    }
};