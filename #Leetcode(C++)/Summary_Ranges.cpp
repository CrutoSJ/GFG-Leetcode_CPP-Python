/* It seems like the start of a code solution to a problem that involves finding the smallest sorted
list of ranges that cover all the numbers in a sorted unique integer array. The problem statement is
provided as a comment and the solution is likely to follow in the code. */
// #Question:-

// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0)
            return result;
        int a = nums[0];
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                if (nums[i] != a)
                    result.push_back(to_string(a) + "->" + to_string(nums[i]));
                else
                    result.push_back(to_string(a));
                if (i != n - 1)
                    a = nums[i + 1];
            }
        }
        return result;
    }
};

int main() {
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter no. of elements: ";
        cin >> n;

        vector<int> nums(n);

        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution solution;
        vector<string> a = solution.summaryRanges(nums);

        cout << "Summary Ranges: ";
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}