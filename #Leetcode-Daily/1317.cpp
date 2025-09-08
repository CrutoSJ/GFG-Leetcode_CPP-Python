// #Question:-

// Link -> https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08

// Date -> 08/09/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int place = 1;

        while(n>1){
            int take = 1;

            if(n%10 == 1){
                take = 2;
            }

            a = a-take*place;
            b = b+take*place;

            n = (n-take)/10;

            place *= 10;
        }

        return {a,b};
    }
};
