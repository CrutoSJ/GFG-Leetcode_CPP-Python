// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/edit-distance3702/1

// Date-> 02/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int editDistance(string str1, string str2) {
        int n=str1.length(), m=str2.length();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0] = i; 
        }
        
        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                }
            }
        }
        
        return dp[n][m];
    }
};