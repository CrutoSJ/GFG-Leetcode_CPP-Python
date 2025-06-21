// #Question:-

// Link-> https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/?envType=daily-question&envId=2025-06-21

// Date-> 21/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        vector<int> freq(26,0);

        for(int i=0; i<n; i++){
            freq[word[i]-'a']++;
        }

        sort(freq.begin(), freq.end());

        int i=0;
        while(freq[i] == 0) i++;

        int res = n;
        int cumSum = 0;

        while(i<26){
            int dlt = cumSum;
            for(int j=25; j>i; j--){
                if(freq[j] - freq[i] > k){
                    dlt += freq[j] - freq[i] - k;
                } else {
                    break;
                }
            }
            cumSum += freq[i];
            res = min(res, dlt);
            i++;
        }
        return res;
    }
};
