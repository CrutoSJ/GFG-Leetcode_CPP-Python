/* The given question is asking us to find the maximum score we can achieve by performing a specific
operation on an array `nums` exactly `k` times. */
// #Question:-

// You are given a 0-indexed integer array nums and an integer k. Your task is to perform the following operation exactly k times in order to maximize your score:

// Select an element m from nums.
// Remove the selected element m from the array.
// Add a new element with a value of m + 1 to the array.
// Increase your score by m.
// Return the maximum score you can achieve after performing the operation exactly k times.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        return (*max_element(nums.begin(), nums.end())) * k + (k - 1) * k / 2;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    while (t--) {
        int n, k;
        cout << "Enter the size of the array and k: ";
        cin >> n >> k;

        vector<int> nums(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        Solution solution;
        int maxScore = solution.maximizeSum(nums, k);
        cout << "Maximum score: " << maxScore << endl;
    }

    return 0;
}
