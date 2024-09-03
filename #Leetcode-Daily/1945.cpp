// #Question:-

// Link-> https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03

// Date-> 03/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for (char ch : s) {
            int position = ch - 'a' + 1;
            while (position > 0) {
                num += position % 10;
                position /= 10;
            }
        }
        for (int i = 1; i < k; ++i) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            num = digitSum;
        }
        return num;
    }
};