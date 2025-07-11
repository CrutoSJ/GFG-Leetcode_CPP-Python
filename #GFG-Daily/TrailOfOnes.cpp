// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

// Date-> 11/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countConsec(int n) {
        if(n == 2){
            return 1;
        }
        
        int firstNum = 0;
        int secNum   = 1;
        int thirdNum;
        int res = 1;
        
        for(int i=3; i<=n; i++){
            
            thirdNum = firstNum + secNum;
            res = res * 2 + thirdNum;
            
            firstNum = secNum;
            secNum   = thirdNum;
        }
        
        return res;
    }
};