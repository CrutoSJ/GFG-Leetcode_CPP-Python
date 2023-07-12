// Question:-

// You are given an integer n and an integer start.

// Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

// Return the bitwise XOR of all elements of nums.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int xorOperation(int n, int start) {
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = start + 2*i;
        }

        int ans  = 0;

        for(int i=0;i<n;i++)
        {
            ans = ans ^ arr[i];
        }

        return ans;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n, start;
        cout << "Enter the value of n: ";
        cin >> n;
        cout << "Enter the value of start: ";
        cin >> start;
        
        Solution obj;
        int xorResult = obj.xorOperation(n, start);
        cout << "Bitwise XOR of all elements of nums: " << xorResult << endl;
    }
    return 0;

}