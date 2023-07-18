// Question:-

// We are given a list nums of integers representing a list compressed with run-length encoding.

// Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.

// Return the decompressed list.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i+=2){
            while(nums[i]--){
                ans.push_back(nums[i+1]); 
            }
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
        cout << "Enter the number of elements in the compressed list: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the compressed list: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution obj;
        vector<int> decompressedList = obj.decompressRLElist(nums);
        cout << "Decompressed List: ";
        for (int num : decompressedList) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

}