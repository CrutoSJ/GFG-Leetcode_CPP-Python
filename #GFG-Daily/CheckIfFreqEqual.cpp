// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/check-frequencies4211/1

// Date-> 25/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isEqual(vector<int> &v){
        int check = -1;
        for(int i=0;i<26;i++){
            if(v[i]){
                if(check == -1) check = v[i];
                if(check != v[i]) return 0;
            }
        }
        
        return 1;
    }
  public:
    bool sameFreq(string& s) {
        int n = s.length();
        vector<int> v(26,0);


        for(int i=0;i<n;i++) v[s[i] - 'a']++;
        
        if(isEqual(v)) return true;
        
        for(int i=0;i<26;i++){
            v[i]--;
            if(isEqual(v)) return true;
            v[i]++;
        }
        
        return false;
    }
};