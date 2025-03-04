// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// Date -> 04/03/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int dp[1001][1001];
    int solve(int i, int p, vector<int> &arr)
    {
        if (i >= n)
        {
            return 0;
        }

        if (p != -1 && dp[i][p] != -1)
        {
            return dp[i][p];
        }

        int take = 0;
        if (p == -1 || arr[i] > arr[p])
        {
            take = 1 + solve(i + 1, i, arr);
        }

        int skip = solve(i + 1, p, arr);

        if (p != -1)
        {
            dp[i][p] = max(take, skip);
        }

        return max(take, skip);
    }
    int lis(vector<int> &arr)
    {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, arr);
    }
};