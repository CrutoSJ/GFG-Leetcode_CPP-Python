// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/roof-top-1587115621/1

// Date-> 26/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int maxCnt = INT_MIN;
        int curCnt = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] < arr[i+1]){
                curCnt++;
            } else{
                curCnt = 0;
            }
            maxCnt = max(maxCnt, curCnt);
        }
        return maxCnt;
    }
};