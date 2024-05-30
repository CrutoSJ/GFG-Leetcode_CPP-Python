// #Question:-

// Link-> https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

//Date - 30/05/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i=0; i<n-1; i++){
            int curr_xor = arr[i];
            for(int k=i+1; k<n; k++){
                curr_xor ^= arr[k];
                if(curr_xor==0){
                    res += (k-i);
                }
            }
        }
        return res;
    }
};