// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// Date -> 06/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int m;

    int dp[1001][1001];

    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }
        else
        {
            return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
        }
    }

    int lcs(string &s1, string &s2)
    {
        n = s1.length();
        m = s2.length();

        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0);
    }
};