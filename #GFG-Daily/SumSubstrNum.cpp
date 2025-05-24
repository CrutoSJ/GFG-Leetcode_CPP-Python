// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

// Date-> 24/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n=s.length();
        int sum=0, mul=1;
        
        for(int i=n-i-1; i>=0; i--){
            sum += ((s[i]-'0') * (i+1) * (mul));
            mul = (mul*10)+1;
        }
        
        return sum;
    }
};

