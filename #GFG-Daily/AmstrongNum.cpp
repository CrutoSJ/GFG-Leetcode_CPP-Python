// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

// Date-> 14/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string armstrongNumber(int n) {
        int num = n;
        int sum=0;
        while(num>0){
            int d=num%10;
            num=num/10;
            sum+= d*d*d;
        }
        if(sum==n) return "true";
        return "false";
    }
};