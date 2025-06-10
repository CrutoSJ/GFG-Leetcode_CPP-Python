// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1

// Date-> 10/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countStrings(string &s) {
        int n = s.length();
        vector<int> freq(26,0);
        int res = 0;
        
        for(int i=0; i<n; i++){
            res += (i-freq[s[i] - 'a']);
            freq[s[i]-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(freq[i]>1){
                res++;
                break;
            }
        }
        
        return res;
    }
};
