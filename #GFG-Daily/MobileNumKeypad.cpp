// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

// Date-> 27/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[10][16]; // dp[digit][length]

    unordered_map<int, vector<int>> moves = {
        {0, {0, 8}},
        {1, {1, 2, 4}},
        {2, {2, 1, 3, 5}},
        {3, {3, 2, 6}},
        {4, {4, 1, 5, 7}},
        {5, {5, 2, 4, 6, 8}},
        {6, {6, 3, 5, 9}},
        {7, {7, 4, 8}},
        {8, {8, 5, 7, 9, 0}},
        {9, {9, 6, 8}}
    };

    int countWays(int digit, int len, int n) {
        if (len == n) return 1;

        if (dp[digit][len] != -1) return dp[digit][len];

        int ways = 0;
        for (int next : moves[digit]) {
            ways += countWays(next, len + 1, n);
        }

        return dp[digit][len] = ways;
    }

public:
    int getCount(int n) {
        memset(dp, -1, sizeof(dp));
        int total = 0;
        for (int digit = 0; digit <= 9; digit++) {
            total += countWays(digit, 1, n);
        }
        return total;
    }
};
