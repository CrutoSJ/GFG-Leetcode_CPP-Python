// #Question:-

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> Combinations;
        do {
            Combinations.push_back(nums);
            for (const auto& num : nums) {
                cout << num << " ";
            } 
            cout << endl;
        } while (next_permutation(nums.begin(), nums.end()));

        return Combinations;

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

        cout << "Enter array elements: ";

        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        Solution solution;
        auto a = solution.permuteUnique(nums);

        cout << endl;
    }

    return 0;

}