// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1

// Date - 29/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinner(int n, int x, int y) {
        // code here
        int i;
        vector<bool>dp(n+1,false);
        dp[0]=false;
        dp[1]=true;
        for(i=2; i<=n; i++){
            if(i-1>=0 && !dp[i-1]){
                dp[i] = true;
            }
            if(i-x>=0 && !dp[i-x]){
                dp[i] = true;
            }
            if(i-y>=0 && !dp[i-y]){
                dp[i] = true;
            }
        }
        return dp[n]==true;
    }
};