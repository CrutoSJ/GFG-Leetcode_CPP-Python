// #Question:-

// Link-> https://leetcode.com/problems/count-ways-to-build-good-strings/description/?envType=daily-question&envId=2024-12-30

// Date-> 30/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
private:
    int solve(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        for(int size = high;size >= 0;size--){
            int ans = (low <= size && size <= high) ? 1 : 0;
            if(size+zero <= high)
            ans = (ans + dp[size+zero]) % MOD;
            if(size+one <= high)
            ans = (ans + dp[size+one]) % MOD;
            
            dp[size] = ans;
        }
            return dp[0];

    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(low, high, zero, one);
    }
};