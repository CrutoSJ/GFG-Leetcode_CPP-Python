// #Question:-

// Link-> 05/09/24

// Date-> 05/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int findSum(int n){
        if(n==0 || n==1){
            return n;
        }
        
        return n + findSum(n-1);
    }

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        int sum = accumulate(arr.begin(), arr.end(), 0);
        int num = findSum(n);
        
        return num-sum;
    }
};