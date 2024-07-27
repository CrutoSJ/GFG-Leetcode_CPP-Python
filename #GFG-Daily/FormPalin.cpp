// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1

// Date-> 27/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int LCS(int n, string s1, string s2){
        int dp[n+1][n+1];
        
        //base case:-
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        
        //recursive case:-
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
public:
    int countMin(string str){
        string rev=str;
        int n = str.length();
        reverse(rev.begin(), rev.end());
        return n-LCS(n,str,rev);
        
    }
};