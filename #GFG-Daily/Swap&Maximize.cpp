// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1

// Date-> 01/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int i=0, j=n-1;
        while(i<j){
            sum += abs(arr[i]-arr[j]);
            sum += abs(arr[j]-arr[i+1]);
            i++,j--;
        }
        sum += abs(arr[n/2]-arr[0]);
        return sum;
    }
};