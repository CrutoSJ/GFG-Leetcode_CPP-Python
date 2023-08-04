// #Question:-

// You are given a 0-indexed array of distinct integers nums.

// There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

// A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

// Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minimumDeletions(vector<int>& nums) {
        int maxindex = 0;
        int minindex = 0;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > nums[maxindex])maxindex=i;
            if(nums[i] < nums[minindex])minindex=i;
        }
        int i=0;
        while(i<min(minindex,maxindex)){
            i++;
        }
        int j=n-1;
        while(j>max(minindex,maxindex)){
            j--;
        }
        int leftwala  = max(maxindex,minindex)+1;
        int rightwala = n-min(minindex,maxindex);
        int midwala = min(minindex,maxindex)+1+(n-max(minindex,maxindex));

        return min(leftwala,min(rightwala,midwala));

    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
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
        Solution sol;
        int result = sol.minimumDeletions(nums);
        cout << "Minimum number of deletions required: " << result << endl;
    }
    return 0;

    
}