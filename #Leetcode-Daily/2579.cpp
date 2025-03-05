// #Question:-

// Link -> https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05

// Date -> 05/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long coloredCells(int n) {
            int t=1;
            long long ans=1;
    
            while(t<=n){
                ans += 4*(t-1);
                t++;
            }
        return ans;
    }
};

class Solution Optimised {
    public:
        long long coloredCells(int n) {
            return 1+(2*(long long)(n-1)*n);
        }
};