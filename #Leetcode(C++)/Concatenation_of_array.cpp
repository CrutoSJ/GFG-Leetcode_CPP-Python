// Question:-

// Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
// Specifically, ans is the concatenation of two nums arrays.
// Return the array ans.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2*n);
        for(int i=0; i<n; i++){
            nums[n + i] = nums [i];
        }
        return nums;
    }
};

int main(){
    int t;
    cout << "Enter the value of t: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter the elements: ";
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        Solution solution;
        auto ans = solution.getConcatenation(nums);

        cout << "Concatenated array: ";
        for (int i = 0; i < 2 * n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}