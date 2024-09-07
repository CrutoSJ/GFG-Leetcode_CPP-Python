// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/nth-natural-number/1

// Date-> 07/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long findNth(long long n) {
        long long ans = 0;
        long long num = 1;
        while(n>0){
            ans+=num*(n%9);
            n/=9;
            num*=10;
        }
        return ans;
    }
};