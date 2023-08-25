// #Question:

// You are given an array nums consisting of positive integers.

// You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.

// Return the number of distinct integers in the final array.

// #Solution:

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
    
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        vector<int> newv(n);
        for(int i=0;i<n;i++){
            int a = reverseDigits(nums[i]);
            nums.push_back(a);
        }
        for(int i=0;i<2*n;i++){
            st.insert(nums[i]);
        }
        return st.size();
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
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        Solution sol;
        int distinctCount = sol.countDistinctIntegers(nums);
        cout << "Distinct Count: " << distinctCount << endl;
    }
    
    return 0;
}