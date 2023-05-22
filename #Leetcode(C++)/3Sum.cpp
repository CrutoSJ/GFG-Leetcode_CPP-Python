// Question:-

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = nums.size();
        vector<vector<int>>trip;
        for(int i=0; i<s-1; i++){
            int j=i+1,k=s-1;
            
            if(i>0 and nums[i] == nums[i-1]) continue;
            
            while(j<k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    trip.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j<k and nums[j] == nums[j+1])j++;
                    
                    while (j<k and nums[k] == nums[k-1])k--;
                    j++;k--;
                }
                
                else if ((nums[i] + nums[j] + nums[k]) < 0)j++;
                
                else k--;
            }
        }  
        return trip;
    }
};

int main(){
    int t;
    cout << "Enter the value of t: ";
    cin >> t;
    while(t--){
            
            
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            
            vector<int> nums(n);
            cout << "Enter the elements:\n";
            for (int i = 0; i < n; i++) {
                cin >> nums[i];
            }
            
            Solution solution;
            vector<vector<int>> result = solution.threeSum(nums);


            cout << "Result:\n";
            for (const vector<int>& triplet : result) {
                for (int num : triplet) {
                    cout << num << " ";
                }
                cout << "\n";
            }
    }
            return 0;
}

