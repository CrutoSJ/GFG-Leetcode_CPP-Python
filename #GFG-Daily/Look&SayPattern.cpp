// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1

// Date-> 14/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    string solve(int n, string num){
        if(n==1){
            return num; 
        }
        string ans = "";
        int cnt=1;
        for(int i=0; i<num.size(); i++){
            if(i<num.size()-1 && num[i]==num[i+1]){
                cnt++;
            } else {
                ans += to_string(cnt);
                ans += num[i];
                cnt = 1;
            }
        }
        return solve(n-1, ans);
    }
  public:
    string countAndSay(int n) {
        return solve(n, "1");
    }
};