#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumMatrix(long long n, long long q) {
        if(q==1 || q>(2*n)) return 0;
        return n-abs(1+n-q);
    }
};