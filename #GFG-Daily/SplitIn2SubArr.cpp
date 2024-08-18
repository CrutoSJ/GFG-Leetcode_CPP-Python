// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

// Date-> 18/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int sum = 0;
        for(auto i : arr){
            sum += i;
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        int currSum = 0;
        for(int i=0; i<arr.size(); i++){
            currSum += arr[i];
            if(currSum == sum/2){
                return true;
            }
        }
        
        return false;
    }
};