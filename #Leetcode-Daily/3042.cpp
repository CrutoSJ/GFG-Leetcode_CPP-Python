// #Question:-

// Link-> https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08

// Date-> 08/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string& first  = words[i];
                string& second = words[j];

                if(first.size() > second.size())continue;
                if(second.find(first) == 0 && second.rfind(first) == second.size() - first.size()){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};