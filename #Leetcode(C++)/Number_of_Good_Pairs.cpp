// Question:-

// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numIdenticalPairs(vector<int>& nums) {
        int a = nums.size();
        int ans = 0;
        for (int i=0; i<a-1; i++ ){
            for (int j=i+1; j<a; j++ ){
                if(nums[i] == nums[j]){
                    ans = ans + 1;
                }
            }
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
        cout << "Enter the size of array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter the array elements: ";


        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        Solution solution;
        auto a = solution.numIdenticalPairs(nums);
        cout << a << endl;
        

    }

}