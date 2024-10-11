// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1

// Date-> 11/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            if(arr[i] != -1){
                res[arr[i]] = arr[i];
            }
        }
        return res;
    }
};