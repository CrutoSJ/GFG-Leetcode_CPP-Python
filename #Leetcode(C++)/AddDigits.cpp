// #Question:-

// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

//Link-> https://leetcode.com/problems/add-digits/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num){
            sum += (num%10);
            num /= 10;
        }

        if(sum<10){
            return sum;
        }
        else{
            return addDigits(sum);
        }
    }
};