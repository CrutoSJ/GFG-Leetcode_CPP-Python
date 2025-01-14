// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

// Date-> 14/01/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n=arr.size(), left=0;
        int right = accumulate(arr.begin(), arr.end(), 0);
        for(int i=0; i<n; i++){
            right-=arr[i];
            if(left==right) return i;
            left+=arr[i];
        }
        return -1;
    }
};