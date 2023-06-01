// Question:-

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> combination;
        do {
            combination.push_back(nums);
            for (const auto& num : nums) {
                cout << num << " ";
            }
            cout << endl;
        } while (next_permutation(nums.begin(), nums.end()));

        return combination;
    }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        vector<int> nums(n);

        cout << "Enter array elements: ";

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution solution;
        auto a = solution.permute(nums);

        cout << endl;
    }
    return 0;
}
