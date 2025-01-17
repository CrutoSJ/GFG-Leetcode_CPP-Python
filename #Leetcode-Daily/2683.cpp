// #Question:-

// Link-> https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17

// Date-> 17/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> res = {0};

        for(int i=0; i<n; i++){
            res.push_back((derived[i]^res[i]));
        }

        bool flag0=(res[0] == res[res.size()-1]);
        res = {1};
        for(int i=0; i<n; i++){
            res.push_back((derived[i]^res[i]));
        }
        bool flag1=(res[0] == res[res.size()-1]);
        return flag0 | flag1;
    }
};