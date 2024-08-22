// #Question:-

// Link-> https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22

// Date-> 22/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int num){
        int mask = 0;
        int temp = num;

        while(temp>0){
            mask = (mask<<1) | 1;
            temp = (temp>>1);
        }

        return num^mask;
    }
    int findComplement(int num) {
        return solve(num);
    }
};