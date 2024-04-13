// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/sum-of-products5049/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long  ans =0;
        for(int i = 0; i < 32; i++){
            long long  k = 0;
            for(int j = 0; j < n; j++){
                if((arr[j] & (1 << i)) != 0 )
                k++;
            }
            ans += (1<< i)*((k) * (k -1)) >> 1;
        }
        return ans;
    }
};