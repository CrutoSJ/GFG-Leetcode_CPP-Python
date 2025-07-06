// #Question:-

// Link-> https://leetcode.com/problems/finding-pairs-with-a-certain-sum/?envType=daily-question&envId=2025-07-06

// Date-> 06/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            ++cnt[num];
        }
    }

    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }

    int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            int rest = tot - num;
            if (cnt.count(rest)) {
                ans += cnt[rest];
            }
        }
        return ans;
    }
};