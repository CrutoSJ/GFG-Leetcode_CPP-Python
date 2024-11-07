// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1

// Date-> 07/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%3 != 0){
            return {-1,-1};
        }
        int reqSum = sum/3;
        int curSum = 0, cnt = 0;
        vector<int> res;
        
        for(int i=0; i<arr.size(); i++){
            curSum += arr[i];
            if(curSum == reqSum){
                res.push_back(i);
                cnt++;
                curSum = 0;
            }
            
            if(cnt==2)break;
        }
        
        if(cnt==2)return res;
        return{-1,-1};
    }
};