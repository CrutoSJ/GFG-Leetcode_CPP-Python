// #Question:-

// Link -> https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

// Date -> 04/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n>0){
                if(n%3==2){
                    return false;
                }
                n/=3;
            }
            return true;
        }
    };