// Question:-

// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){

            nums[i]+=nums[i-1];
    }

    return nums;
    }

};

int main(){
    int t;
    cout << "Enter the no.of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter no. of elements of array: ";
        cin >> n;

        vector<int> nums(n);

        cout << "Enter array elements: ";

        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        Solution solution;
        auto a = solution.runningSum(nums);

        for(int i=0; i<n; i++){
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}