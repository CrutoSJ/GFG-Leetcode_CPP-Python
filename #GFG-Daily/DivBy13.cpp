// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/divisible-by-13/1

// Date-> 15/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool divby13(string &s) {
        int num = 0;
        for(int i=0; i<s.size(); i++){
            num = (num * 10 + s[i] - '0')%13;
        }
        return num==0;
    }
};
