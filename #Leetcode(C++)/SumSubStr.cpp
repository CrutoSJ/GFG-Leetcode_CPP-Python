// #Question 

// #Link-> https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

// #solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int mod=int(1e9)+7;
    public:
    long long sumSubstrings(string s){
        long long n=s.size();
        long long rep=0;
        long long prev=0, sum=0;
        for(int i=n-1;i>=0;i--){
            long long num=s[i]-'0';
            // long long rep=(pow(10, n-i)-1)/9;
            rep=((10*rep)%mod+1)%mod;
            prev=(prev+(rep*num)%mod)%mod;
            sum= (sum+prev)%mod;
        }
        return sum;
    }
};