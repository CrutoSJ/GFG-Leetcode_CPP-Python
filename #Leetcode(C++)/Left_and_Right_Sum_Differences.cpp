// #Question:-

// Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

// answer.length == nums.length.
// answer[i] = |leftSum[i] - rightSum[i]|.
// Where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return the array answer.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int> leftRightDifference(vector<int>& nums) {
        int ps = 0, ss = 0;
        for(auto &i: nums)ss += i;
        vector<int> ans;
        for(auto &i: nums){
            ss -= i;
            ans.push_back(abs(ss-ps));
            ps += i;
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
        cout << "Enter size of the array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter elements of the array: ";
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        Solution solution;
        vector<int> answer = solution.leftRightDifference(nums);

        cout << "Answer array is: ";
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << " ";
        }
        cout << endl;
    }

    return 0;

}