// Question:-

// You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

// In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

// Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

// Each answer[i] is calculated considering the initial state of the boxes.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && boxes[j] == '1') {
                    result[i] += abs(i - j);
                }
            }
        }

        return result;
    }

};

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the size of the string: ";
        cin >> n;

        string boxes;
        cout << "Enter the string: ";
        cin >> boxes;

        Solution solution;
        vector<int> a = solution.minOperations(boxes);

        cout << "Minimum number of operations needed for each box: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}