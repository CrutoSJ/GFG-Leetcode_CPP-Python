// Question:-

// Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
// A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> buildArray(vector<int>& nums) {
        int a = nums.size();
        vector<int> ans(a);
        for(int i=0; i<a; i++){
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter array elements: ";

        for( int i=0; i<n; i++){
            cin >> nums[i];
        }

        Solution solution; 
        auto a = solution.buildArray(nums);

        cout << " Output array: ";

        for (int i=0; i<n; i++){
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}