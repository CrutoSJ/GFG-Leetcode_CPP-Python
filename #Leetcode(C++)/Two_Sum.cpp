// Question:-

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        int s = nums.size();
        for(int i=0; i < s; i++){
            for(int j=i+1; j < s; j++){
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }
};

int main(){
    int t;
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

        int target;
        cout << "Enter the target value: ";
        cin >> target;

        Solution a;
        auto ans = a.twoSum(nums,target);
        
        if( ans.empty()){
            cout << "No solution" << endl;
        }
        else{
        cout << "Indices: ";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        }
    }
    return 0;


}