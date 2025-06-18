// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

// Date-> 18/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPalindrome(string &s, int l, int h){
        while(l<h){
            if(s[l] != s[h]){
                return false;
            }
            l++, h--;
        }
        return true;
    }
    void solve(int idx, string &s, vector<vector<string>> &res, vector<string> &curr){
        if( idx == s.size()){
            res.push_back(curr);
            return ;
        }
        
        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, res, curr);
                curr.pop_back();
            }
        }
        
        return ;
    }
  public:
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> res;
        vector<string> curr;
        solve(0, s, res, curr);
        return res;
    }
};