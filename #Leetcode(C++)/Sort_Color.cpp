// Question:-

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void sortColors(vector<int>& nums) {
        int kam = 0, madhya = 0, jyada = nums.size()-1;
        while(madhya <= jyada){
            if(nums[madhya] == 0){
                swap(nums[kam], nums[madhya]);
                kam++;
                madhya++;
            }
            else if(nums[madhya] == 1){
                madhya++;
            }
            else{
                swap(nums[madhya], nums[jyada]);
                jyada--;
            }
        }
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        
        vector<int> nums(n);
        cout << "Enter " << n << " elements (0 for red, 1 for white, 2 for blue): ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution obj;
        obj.sortColors(nums);

        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
    
}