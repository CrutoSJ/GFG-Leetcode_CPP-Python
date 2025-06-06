// #Question:-

// Link-> https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06

// Date-> 06/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharRight(n);
        minCharRight[n-1] = s[n-1];

        for(int i=n-2; i>=0; i--){
            minCharRight[i] = min(s[i], minCharRight[i+1]);
        }

        string t = "";
        string p = "";
        int i=0;

        while(i<n){
            t.push_back(s[i]);
            char minChar = i+1<n ? minCharRight[i+1] : s[i];

            while(!t.empty() && t.back() <= minChar){
                p += t.back();
                t.pop_back();
            }

            i++;
        }

        while(!t.empty()){
            p += t.back();
            t.pop_back();
        }

        return p;
    }
};