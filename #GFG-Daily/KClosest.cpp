// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
 
        vector<int>ans;
        
        for(int i = 0; i<k; i++){
            int diff = INT_MAX;
            int val = -1;
            for(int j = 0; j<n; j++){
                if(arr[j] != -1 && arr[j] != x){
                    if(abs(x-arr[j])<=diff){
                        diff = abs(x-arr[j]);
                        val = j;
                    }
                }
            }

            
            ans.push_back(arr[val]);
            arr[val] = -1;
        }
        
        return ans;
    }
};