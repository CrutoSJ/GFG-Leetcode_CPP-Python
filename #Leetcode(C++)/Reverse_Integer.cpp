// #Question:-

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long RevNum = 0;
        while (x != 0) {
            int ld = x % 10;
            RevNum = (RevNum * 10) + ld;
            x = x / 10;
        }

        if (RevNum < INT_MIN || RevNum > INT_MAX) {
            return 0;
        }

        return static_cast<int>(RevNum);
    }
};

int main() {
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int x;
        cout << "Enter a number: ";
        cin >> x;

        Solution solution;
        int reversedNum = solution.reverse(x);

        cout << "Reversed number: " << reversedNum << endl;

    }

        return 0;
}
