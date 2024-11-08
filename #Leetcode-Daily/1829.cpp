// #Question:-

// Link-> https://leetcode.com/problems/maximum-xor-for-each-query/description/?envType=daily-question&envId=2024-11-08

// Date-> 08/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
        }

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            int currentXOR = prefixXOR[n - 1 - i];
            ans[i] = currentXOR ^ mask;
        }

        return ans;
    }
};