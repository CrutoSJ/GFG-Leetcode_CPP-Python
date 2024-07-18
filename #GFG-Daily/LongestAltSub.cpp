// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

// Date-> 18/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingMaxLength(vector<int>& arr) {
        int cb = 1;
        int bc = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]>arr[i-1]){
                cb = 1+bc;
            } else if(arr[i]<arr[i-1]){
                bc = 1+cb;
            } 
        }
        return max(cb, bc);
    }
};