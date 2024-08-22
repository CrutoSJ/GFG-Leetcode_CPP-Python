// #Question:-

// Link-> https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20

// Date-> 20/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[2][101][101];

    int playForAlice(vector<int>& piles, int person, int idx, int M){
        if(idx>=n){
            return 0;
        }

        if(dp[person][idx][M] != -1){
            return dp[person][idx][M];
        }

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;

        for(int i=1; i<=min(2*M, n-idx); i++){
            stones += piles[idx+i-1];

            if(person == 1){//Alice
                result = max(result, stones + playForAlice(piles, 0, idx+i, max(i, M)));
            } else{//BOB
                result = min(result, playForAlice(piles, 1, idx+i, max(i, M)));
            }
        }

        return dp[person][idx][M] = result ;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return playForAlice(piles, 1, 0, 1); // vec, person, idx, M
    }
};