// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

// Date - 31/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swapNibbles(int n) {
        int rn=n & (0b11110000);
        int ln=n & (0b00001111);
        
        rn=rn>>4;
        ln=ln<<4;
        
        return rn | ln;
    }
};