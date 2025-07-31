// #Question:-

// Date-> 31/07/25

// Link-> https://leetcode.com/problems/bitwise-ors-of-subarrays/submissions/1718593404/?envType=daily-question&envId=2025-07-31

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        set<int> curr, next;

        for (int num : arr) {
            next = {num};
            for (int x : curr)
                next.insert(x | num);
            curr = next;
            result.insert(curr.begin(), curr.end());
        }

        return result.size();
    }
};