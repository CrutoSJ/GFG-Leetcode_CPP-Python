// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

// Date-> 04/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string binaryNextNumber(string s) {
        reverse(s.begin(), s.end());
        int carry = 1;
        int n = s.length();
        for(int i=0; i<n && carry == 1; i++){
            if(s[i] == '0'){
                s[i] = '1';
                carry = 0;
            } else{
                s[i] = '0';
                carry = 1;
            }
        }
        if(carry) {
            s=s+'1';
        }
        reverse(s.begin(), s.end());
        int idx=0;
        while(s[idx] == '0'){
            idx++;
        }
        n = s.length();
        return s.substr(idx,n-idx);
    }
};