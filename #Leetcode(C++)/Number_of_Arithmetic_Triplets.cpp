// #Question:-

// You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

// i < j < k,
// nums[j] - nums[i] == diff, and
// nums[k] - nums[j] == diff.
// Return the number of unique arithmetic triplets.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0 ;
  
    for(int i=0 ;i<nums.size()-2 ;i++){
        int count = 0 ;
        for(int j=i+1 ; j<nums.size() ;j++){
             
            if(nums[j]-nums[i]==diff || nums[j]-nums[i]==2*diff){
                count++;
            }
        }
        if(count==2){
            ans++;
        }
    }
    return ans ;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n, diff;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << "Enter the value of diff: ";
        cin >> diff;

        Solution sol;
        int result = sol.arithmeticTriplets(nums, diff);
        cout << "Number of unique arithmetic triplets: " << result << endl;
    }
    return 0;
}