// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/padovan-sequence2855/1

// Date-> 13/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int padovanSequence(int n) {
        if(n==1 || n==2 || n==0){
            return 1;
        }
        
        long long p0=1, p1=1, p2=1;
        
        for(int i=3; i<n+1; ++i){
            long long p_next = (p0+p1)%MOD;
            p0=p1;
            p1=p2;
            p2=p_next;
        }
        return p2;
    }
};