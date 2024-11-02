// #Question:-

// Link-> https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02

// Date-> 02/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sen) {
        int n = sen.size();
        if(sen[0] != sen[n-1]) return false;
        int i = 0;
        while(i<n){
            if(sen[i] == ' ' && sen[i-1] != sen[i+1]) return false;
            i++;
        }
        return true;
    }
};