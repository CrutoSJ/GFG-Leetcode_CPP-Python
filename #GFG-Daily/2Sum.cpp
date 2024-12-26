// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/key-pair5616/1

// Date-> 26/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int i=0, j=arr.size()-1;
        
        while(i<j){
            int sum = arr[i] + arr[j];
            if(sum == target){
                return true;
            } else if(sum < target){
                i++;
            } else{
                j--;
            }
        }
        return false;
    }
};