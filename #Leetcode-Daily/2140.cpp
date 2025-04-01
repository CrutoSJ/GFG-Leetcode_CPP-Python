// #Question:-

// Link-> https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01

// Date-> 01/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        ll mx = 0;
        vector<ll> dp(n);
        dp[n - 1] = questions[n - 1][0];
        for(int i = n - 2; i >= 0; --i) {
            dp[i] = questions[i][0];
            if(i + questions[i][1] + 1 < n)
                dp[i] += dp[i + questions[i][1] + 1];
            
            dp[i] = max(dp[i], dp[i + 1]);
        }

        return dp[0];
    }
};