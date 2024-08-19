// #Question:-

// Link-> https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19

// Date-> 19/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFactorSum(int n, int i, int &sum){
        if(n==1){
            return sum;
        }
        if(n % i == 0){
            sum += i;
            n = n/i;
            return findFactorSum(n, i, sum);
        } else{
            return findFactorSum(n, i+1, sum);
        }
    }

    int minSteps(int n) {
        if(n == 1){
            return 0;
        }

        int sum = 0;
        findFactorSum(n,2,sum);
        return sum;
    }
};