// #Question:-

// Link-> https://leetcode.com/problems/distribute-candies-among-children-ii/description/?envType=daily-question&envId=2025-06-01

// Date-> 01/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};