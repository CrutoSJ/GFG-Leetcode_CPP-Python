// #Question:-

// Link-> https://leetcode.com/problems/minimum-array-end/description/?envType=daily-question&envId=2024-11-09

// Date-> 09/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        while(--n){
            res = (res+1)|x;
        }
        return res;
    }
};