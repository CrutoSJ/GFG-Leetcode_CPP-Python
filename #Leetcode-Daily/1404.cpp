// #Question:-

// Link-> https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

// Date - 29/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numSteps(string s){
        int count = 0;
        int carry = 0;
        for(int i=s.length()-1; i>0; --i){
            if(s[i]-'0'+carry == 1){
                carry = 1;
                count += 2;
            } else{
                count += 1;
            }
        }

        return count+carry;
    }
};