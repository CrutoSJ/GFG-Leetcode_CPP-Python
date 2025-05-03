// #Question:-

// Link-> https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03

// Date-> 03/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            const int n = tops.size();
            if (bottoms.size() != n) {
                return -1;
            }
            unordered_map<int, int> freqT;
            unordered_map<int, int> freqB;
            unordered_map<int, int> freqEq;
            for (int i = 0; i < n; ++i) {
                int t = tops[i], b = bottoms[i];
                ++freqT[t];
                ++freqB[b];
                freqEq[t] += t == b; 
            }
            int res = INT_MAX;
            for (int i = 1; i < 7; ++i) {
                int t = freqT[i], b = freqB[i];
                if (t + b - freqEq[i] == n) {
                    res = min(res, min(n - t, n - b));
                }
            }
            return res == INT_MAX ? -1 : res;
        }
    };