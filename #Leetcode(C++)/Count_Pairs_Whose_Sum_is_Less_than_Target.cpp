// #Question:-

// Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countPairs(vector<int>& nums, int target) {
        int cnt = 0 ;
        int n = nums.size();
        multiset<int>st ;
        for(int i = 0 ; i < n ;i++){
            auto pos = st.lower_bound(target-nums[i]);
            cnt += distance(st.begin(),pos);
            st.insert(nums[i]);
        }
        return cnt ;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;
    while(t--){
        int n, target;
        cout << "Enter the length of array and target: ";
        cin >> n >> target;

        vector<int> nums(n);
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution solution;
        int result = solution.countPairs(nums, target);
        cout << "Number of pairs where sum is less than target: " << result << endl;
    }

    return 0;
}