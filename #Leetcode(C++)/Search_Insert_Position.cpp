// Question:-

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int searchInsert(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){

            int mid = left + ( right - left ) / 2;

            if ( nums[mid] == target){
                return mid;
            } else if ( nums[mid] < target){
                left = mid + 1;
            } else {
                right = right - 1;
            }
        }
        return left;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter the elements: ";
        for(int i=0; i < n; i++){
            cin >> nums[i];
        }

        int target;
        cout << "Enter target value: ";
        cin >> target;

        Solution a;
        auto ans = a.searchInsert(nums, target);
        cout << ans << endl;
    }

    return 0;

}