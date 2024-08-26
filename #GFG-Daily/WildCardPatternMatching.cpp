// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1

// Date-> 26/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[201][201];
    int solve(string pattern, string str, int i, int j){
        if(i == pattern.length() && j == str.length()){
            return 1;
        }
        
        if(i == pattern.length()){
            return 0;
        }
        
        if(j == str.length() && pattern[i] == '*'){
            return solve(pattern, str, i+1, j);
        }
        
        if(j == str.length()){
            return 0;
        }
        
        if(pattern[i] != '*' && pattern[i] != '?' && pattern[i] != str[j]){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        
        int a=0, b=0, c=0;
        if(pattern[i] == '*'){
            a = solve(pattern, str, i+1, j);
            b = solve(pattern, str, i, j+1);
        }
        
        c = solve(pattern, str, i+1, j+1);
        
        return dp[i][j] = a||b||c;
    }
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        memset(dp, -1, sizeof(dp));
        return solve(pattern, str, 0, 0);
    }
};