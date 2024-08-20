// #Question:-

// Link-> https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20

// Date-> 20/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[101][101];// stones diff
    int alice(int i, int m, vector<int>& piles){
        if (i == n) return 0;
        if (dp[i][m]!=-1) return dp[i][m];
        int diff=INT_MIN;
        int sum = 0, xN= min(2*m, n-i);
        for (int x = 1; x <= xN; x++) {
            sum += piles[i+x-1];
            diff=max(diff, sum-alice(i+x, max(m, x), piles));                      
        }
        return dp[i][m]=diff;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        int sum=accumulate(piles.begin(), piles.end(), 0);
        return (sum+alice(0, 1,  piles))/2;// A=((A+B)+(A-B))/2
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();