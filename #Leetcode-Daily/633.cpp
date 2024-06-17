// #Question:-

// Link-> https://leetcode.com/problems/sum-of-square-numbers/

// Date-> 17/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int s=0;
        long long e=sqrt(c);
        while(s<=e){
            long long ans = s*s+e*e;
            if(ans == c) return true;
            else if(ans<c) s++;
            else e--;
        }
        return false;
    }
};