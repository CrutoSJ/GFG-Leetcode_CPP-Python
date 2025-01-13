// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// Date-> 13/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> freq;
        for(char &ch:s){
            freq[ch]++;
        }

        int Cnt=0;
        for(auto &x:freq){
            int temp = x.second;
            if(temp%2==1){
                Cnt += temp-1;
            } else{
                Cnt += temp-2;
            }
        }
        return s.length()-Cnt;
    }
};