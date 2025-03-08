// #Question:-

// Link -> https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08

// Date -> 08/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n=blocks.size(), i=0, j=0, ops=k, W=0;
    
            while(j<n){
                if(blocks[j]=='W'){
                    W++;
                }
    
                if(j-i+1>=k){
                    ops=min(ops,W);
                    if(blocks[i]=='W'){
                        W--;
                    }
                    i++;
                }
                j++;
            }
            return ops;
        }
    };