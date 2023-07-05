// Question:-

// Given two arrays of integers nums and index. Your task is to create target array under the following rules:

// Initially target array is empty.
// From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
// Repeat the previous step until there are no elements to read in nums and index.
// Return the target array.

// It is guaranteed that the insertion operations will be valid.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
	{
		vector<int> target;
		for (int i = 0; i < nums.size(); i++)
		{
			target.insert(target.begin() + index[i], nums[i]);
		}

		return target;
	}
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of the arrays: ";
        cin >> n;

        vector<int> nums(n), index(n);
        cout << "Enter the elements of the nums array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "Enter the elements of the index array: ";
        for (int i = 0; i < n; i++) {
            cin >> index[i];
        }

        Solution obj;
        vector<int> target = obj.createTargetArray(nums, index);

        cout << "Target Array: ";
        for (int i = 0; i < target.size(); i++) {
            cout << target[i] << " ";
        }
        cout << endl;
    }

    return 0;

}