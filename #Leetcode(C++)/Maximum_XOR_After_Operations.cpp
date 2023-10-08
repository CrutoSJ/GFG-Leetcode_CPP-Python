// #Question:-

// You are given a 0-indexed integer array nums. In one operation, select any non-negative integer x and an index i, then update nums[i] to be equal to nums[i] AND (nums[i] XOR x).

// Note that AND is the bitwise AND operation and XOR is the bitwise XOR operation.

// Return the maximum possible bitwise XOR of all elements of nums after applying the operation any number of times.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;;
        for(auto &i: nums){
            ans |= i;
        }
        return ans;
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

        vector<int> nums(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution solution;
        int result = solution.maximumXOR(nums);
        cout << "Maximum XOR of array elements: " << result << endl;
    }

    return 0;
}