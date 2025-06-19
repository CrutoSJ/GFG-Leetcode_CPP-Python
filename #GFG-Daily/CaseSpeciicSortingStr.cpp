// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

// Date-> 19/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string caseSort(string& s) {
        int n = s.length();
        string uc = "";
        string lc = "";
        
        for(int i=0; i<n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                uc += s[i];
            } else if(s[i] >= 'a' && s[i] <= 'z'){
                lc += s[i];
            }
        }
        
        sort(uc.begin(), uc.end());
        sort(lc.begin(), lc.end());
        
        int i=0;
        int j=0;
        int idx = 0;
        
        while(i<uc.length() && j<lc.length()){
            if(s[idx] >= 'A' && s[idx] <= 'Z'){
                s[idx++] = uc[i++];
            } else{
                s[idx++] = lc[j++];
            }
        }
        
        while(i<uc.length()){
            s[idx++] = uc[i++];
        }
        
        while(j<lc.length()){
            s[idx++] = lc[j++];
        }
        
        return s;
    }
};