// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-sum-of-smallest-and-second-smallest-in-an-array/1

// Date-> 12/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        if(arr.size()==1){
            return -1;
        }
        int maxi = INT_MIN;
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1] + arr[i] > maxi){
                maxi = arr[i-1] + arr[i];
            }
        }
        return maxi;
    }
};