// Question:-

// Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

// A subarray is a contiguous subsequence of the array.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int sumOddLengthSubarrays(std::vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            int frequency = ((i + 1) * (n - i) + 1) / 2;
            totalSum += arr[i] * frequency;
        }

        return totalSum;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        std::vector<int> arr(n);
        cout << "Enter " << n << " positive integers: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution solution;
        int result = solution.sumOddLengthSubarrays(arr);
        cout << "Sum of all possible odd-length subarrays: " << result << endl;
    }

    return 0;

}