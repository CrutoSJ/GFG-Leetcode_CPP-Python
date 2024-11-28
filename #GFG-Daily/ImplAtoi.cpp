// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/implement-atoi/1

// Date-> 28/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(char *s) {
        int i=0;
        long ans=0;
        int sign = 1;
        
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '+' || s[i] == '-'){
            sign = (s[i] == '-')?-1:1;
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            ans = ans*10 + (s[i] - '0');
            if(sign*ans <= INT_MIN) return INT_MIN;
            if(sign*ans >= INT_MAX) return INT_MAX;
            i++;
        }
        return sign*ans;
    }
};