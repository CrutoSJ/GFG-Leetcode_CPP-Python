// #Question:-

// Link-> https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/?envType=daily-question&envId=2025-07-04

// Date-> 04/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k = k - ((long long)1 << t);
            if (operations[t]) {
                ans++;
            }
        }
        return 'a' + (ans % 26);
    }
};