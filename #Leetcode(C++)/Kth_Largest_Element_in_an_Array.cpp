// #Question:-

// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Can you solve it without sorting?

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    while(t--) {
        int n, k;
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        
        vector<int> nums(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        cout << "Enter k: ";
        cin >> k;

        Solution obj;
        int result = obj.findKthLargest(nums, k);
        cout << "The kth largest element is: " << result << endl;
    }

    return 0;
}