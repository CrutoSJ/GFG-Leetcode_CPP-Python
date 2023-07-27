// Question:-

// There is a hidden integer array arr that consists of n non-negative integers.

// It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

// You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

// Return the original array arr. It can be proved that the answer exists and is unique.

// Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> v;
        v.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            v.push_back(encoded[i] ^ v[i]);
        }
        return v;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while (t--) {
        int n, first;
        cout << "Enter the length of the encoded array: ";
        cin >> n;

        vector<int> encoded(n - 1);
        cout << "Enter the elements of the encoded array: ";
        for (int i = 0; i < n - 1; i++) {
            cin >> encoded[i];
        }

        cout << "Enter the first element of the original array: ";
        cin >> first;

        Solution obj;
        vector<int> arr = obj.decode(encoded, first);

        cout << "The original array is: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}