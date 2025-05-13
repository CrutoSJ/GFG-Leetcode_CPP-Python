// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/ncr1019/1

// Date-> 13/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int nCr(int n, int r) {
        if(r > n || r < 0){
            return 0;
        }
        
        if(r > n-r){
            r = n-r;
        }
        
        long bio_coff = 1;
        for(int i=1; i<=r; i++){
            bio_coff *= (n-i+1);
            bio_coff /=i;
        }
        return (int) bio_coff;
        
    }
};