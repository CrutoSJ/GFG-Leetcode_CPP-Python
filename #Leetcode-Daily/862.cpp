// #Question:-

// Link-> https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/?envType=daily-question&envId=2024-11-17

// Date-> 17/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int targetSum) {
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
        }

        deque<int> candidateIndices;

        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            while (!candidateIndices.empty() && prefixSums[i] - prefixSums[candidateIndices.front()] >= targetSum) {
                shortestSubarrayLength =
                    min(shortestSubarrayLength, i - candidateIndices.front());
                candidateIndices.pop_front();
            }

            while (!candidateIndices.empty() && prefixSums[i] <= prefixSums[candidateIndices.back()]) {
                candidateIndices.pop_back();
            }

            candidateIndices.push_back(i);
        }

        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }
};