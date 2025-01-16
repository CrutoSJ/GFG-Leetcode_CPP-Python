// #Question:-

// Link-> https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16

// Date-> 16/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1=0;
        int x2=0;

        int s1=nums1.size();
        int s2=nums2.size();

        if(s2%2 != 0){
            for(int num:nums1){
                x1^=num;
            }
        }

        if(s1%2 != 0){
            for(int num:nums2){
                x2^=num;
            }
        }
        return x1^x2;
    }
};