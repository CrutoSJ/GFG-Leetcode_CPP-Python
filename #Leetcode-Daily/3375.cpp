// #Question:-

// Link-> https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09

// Date-> 09/04/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> st;
            for (int x : nums) {
                if (x < k) {
                    return -1;
                } else if (x > k) {
                    st.insert(x);
                }
            }
            return st.size();
        }
    };