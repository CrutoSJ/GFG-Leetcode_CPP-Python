// #Question:-

// Link-> https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/submissions/1646045760/

// Date-> 27/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;

        return n*(n+1)/2 - m * k * (k+1);
    }
};
