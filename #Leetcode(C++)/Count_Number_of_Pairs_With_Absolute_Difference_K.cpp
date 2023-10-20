// #Question:-

// Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

// The value of |x| is defined as:

// x if x >= 0.
// -x if x < 0.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countKDifference(vector<int>& nums, int k) {
        int x=0;
        sort(nums.begin(),nums.end(),greater<>());//sort decendingly
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]-nums[j]==k)
                x++;//count the pairs
            }
        }
        return x;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n, k;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << "Enter the value of k: ";
        cin >> k;

        Solution solution;
        int result = solution.countKDifference(nums, k);
        cout << "Number of pairs with |nums[i] - nums[j]| == " << k << ": " << result << endl;
    }
    return 0;
}