// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

// Date-> 22/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int> &lpsArr, string str){
        int i=0;
        int j=1;
        
        while(j<str.length()){
            if(str[i] == str[j]){
                i++;
                lpsArr[j] = i;
                j++;
            } else{
                if(i==0){
                    j++;
                } else{
                    i=lpsArr[i-1];
                }
            }
        }
        
    }
    
    int lps(string str) {
        vector<int> lpsArr(str.length(), 0);
        solve(lpsArr, str);
        return lpsArr[str.length()-1];
    }
};