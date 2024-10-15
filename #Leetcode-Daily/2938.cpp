// #Question:-

// Link-> https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

// Date-> 15/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.length();
        long long ZCnt = 0;
        long long res = 0;

        for(long long i=n-1; i>=0; i--){
            if(s[i] == '0'){
                ZCnt++;
            } else{
                res += ZCnt;
            }
        }
        return res;
    }
};