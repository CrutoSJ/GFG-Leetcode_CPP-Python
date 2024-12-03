// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1

// Date-> 03/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string merged = s+'$'+rev;
        int n = merged.size(), i=0, j=1;
        vector<int> lps(n,0);
        while(j<n){
            if(merged[i] == merged[j]){
                lps[j++]=++i;
            } else if(i!=0){
                i=lps[i-1];
            } else{
                j++;
            }
        }
        return s.length()-i;
    }
};