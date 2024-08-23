// #Question:-

// Link-> https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23

// Date-> 23/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    void findGCD(int &num, int &den){
        int GCD = abs(__gcd(num, den));

        num /= GCD;
        den /= GCD;
    }

    string fractionAddition(string exp) {
        int s = exp.length();
        int num = 0;
        int den = 1;
        
        int i=0;
        while(i<s){
            int currNum = 0;
            int currDen = 0;
            bool isNeg = (exp[i] == '-');
            if(exp[i] == '+' || exp[i] == '-'){
                i++;
            }

            while(i<s && isdigit(exp[i])){
                int val = (exp[i] - '0');
                currNum = (currNum*10) + val;
                i++;
            }

            if(isNeg){
                currNum *= -1;
            }

            i++;

            while(i<s && isdigit(exp[i])){
                int val = (exp[i] - '0');
                currDen = (currDen*10) + val;
                i++;
            }

            num = currDen*num + currNum*den;
            den = den*currDen;
        }

        findGCD(num,den);

        return to_string(num) + "/" + to_string(den);
    }
};