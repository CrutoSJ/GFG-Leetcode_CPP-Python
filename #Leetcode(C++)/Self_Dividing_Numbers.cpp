// #Question:-

// A self-dividing number is a number that is divisible by every digit it contains.

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
// A self-dividing number is not allowed to contain the digit zero.

// Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> arr;
        for (int i = left; i <= right; i++) {
            int x = i;
            int rem;
            int flag = 0;
            while (x != 0) {
                rem = x % 10;
                if (rem == 0) {
                    flag = 1;
                    break;
                }
                if (i % rem != 0) {
                    flag = 1;
                    break;
                }
                x /= 10;
            }
            if (flag == 0) {
                arr.push_back(i);
            }
        }
        return arr;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution solution;

    while (t--) {
        int left, right;
        cout << "Enter left and right: ";
        cin >> left >> right;

        vector<int> result = solution.selfDividingNumbers(left, right);

        cout << "Self-dividing numbers in the range [" << left << ", " << right << "]: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
