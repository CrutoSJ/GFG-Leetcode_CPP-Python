// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

// Date-> 25/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int LeftProd = 1, RightProd = 1;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            LeftProd  *= arr[i];
            RightProd *= arr[n-i-1];
            ans = max({ans, LeftProd, RightProd});
            if(LeftProd == 0)  LeftProd  = 1;
            if(RightProd == 0) RightProd = 1;
        }
        return ans;
    }
};