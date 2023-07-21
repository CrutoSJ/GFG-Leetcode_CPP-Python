// Question:-

// You are given a positive integer array nums.

// The element sum is the sum of all the elements in nums.
// The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
// Return the absolute difference between the element sum and digit sum of nums.

// Note that the absolute difference between two integers x and y is defined as |x - y|.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int differenceOfSum(vector<int>& nums) {
        int oyye=0,hoyye=0;
        for(auto i:nums){
            oyye+=i;
            while(i){
                hoyye+=i%10;
                i/=10;
            }
        }
        return abs(oyye-hoyye);
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        
        vector<int> nums(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        Solution obj;
        int result = obj.differenceOfSum(nums);
        cout << "Absolute difference between element sum and digit sum: " << result << endl;
    }

    return 0;
}