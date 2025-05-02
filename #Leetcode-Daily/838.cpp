// #Question:-

// Link-> https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=2025-05-02

// Date-> 02/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
    
            vector<int> rightClosestL(n);
            vector<int> leftClosestR(n);
    
            for(int i=0; i<n; i++){
                if(dominoes[i] == 'R'){
                    leftClosestR[i] = i;
                } else if(dominoes[i] == '.'){
                    leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
                } else{
                    leftClosestR[i] = -1;
                }
            }
    
            for(int i=n-1; i>=0; i--){
                if(dominoes[i] == 'L'){
                    rightClosestL[i] = i;
                } else if(dominoes[i] == '.'){
                    rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
                } else{
                    rightClosestL[i] = -1;
                }
            }
    
            string res(n, ' ');
    
            for(int i=0; i<n; i++){
                int distRightL = abs(i-rightClosestL[i]);
                int distLeftR = abs(i-leftClosestR[i]);
    
                if(rightClosestL[i] == leftClosestR[i]){
                    res[i] = '.';
                } else if(rightClosestL[i] == -1){
                    res[i] = 'R';
                } else if(leftClosestR[i] == -1){
                    res[i] = 'L';
                } else if(distRightL == distLeftR){
                    res[i] = '.';
                } else{
                    res[i] = distRightL < distLeftR ? 'L' : 'R';
                }
            }
    
            return res;
        }
    };