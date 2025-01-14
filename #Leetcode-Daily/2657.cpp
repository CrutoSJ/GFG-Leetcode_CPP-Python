// #Question:-

// Link-> https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14

// Date-> 14/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> res(n,0);
        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            freq[A[i]]++, freq[B[i]]++;
            for(auto x:freq){
                if(x.second==2){
                    res[i]++;
                }
            }
        }
        return res;
    }
};