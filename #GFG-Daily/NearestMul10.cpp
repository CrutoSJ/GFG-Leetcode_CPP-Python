// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

// Date-> 19/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.length()-1;
        if(str[n] <= '5'){
            str[n] = '0';
            return str;
        }
        str[n] = '0';
        n--;
        while(n>=0 && str[n]=='9'){
            str[n]='0';
            n--;
        }
        if(n==-1){
            return '1'+str;
        }
        str[n]++;
        return str;
    }
};