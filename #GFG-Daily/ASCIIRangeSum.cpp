// #Question:-

// Date-> 29/07/25

// Link-> https://www.geeksforgeeks.org/problems/ascii-range-sum/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.length();
        vector<int> FOcc(26,-1);
        vector<int> LOcc(26,-1);
        
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(FOcc[idx] == -1){
                FOcc[idx] = i;
            }
            LOcc[idx] = i;
        }
        
        vector<int> res;
        
        for(int i=0; i<26; i++){
            if(FOcc[i] != -1 && LOcc[i] != -1 && (FOcc[i] < LOcc[i])){
                int sum = 0;
                for(int idx = FOcc[i]+1; idx<LOcc[i]; idx++){
                    sum += int(s[idx]);
                }
                if(sum!=0){
                    res.push_back(sum);   
                }
            }
        }
        
        return res;
    }
};