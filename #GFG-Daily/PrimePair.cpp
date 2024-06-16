// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-prime4751/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getPrimes(int n) {
        vector<int>primes(n+1,1);
        primes[0]=0;
        primes[1]=0;
        for(int i=2; i<=n; i++){
            for(int j=2; j*i<=n; j++){
                primes[i*j]=0;
            }
        }
        for(int i=0; i<=n/2; i++){
            int j=n-i;
            if(primes[i] && primes[j]){
                return {i,j};
            }
        }
        return {-1,-1};
    }
};