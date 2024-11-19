// #Question:-

// Link-> https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19  

// Date-> 19/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        long long res     = 0;
        long long currSum = 0;

        int i=0, j=0;
        unordered_set<int> st;

        while(j<n){
            while(st.count(arr[j])){
                currSum -= arr[i];
                st.erase(arr[i]);
                i++;
            }

            currSum += arr[j];
            st.insert(arr[j]);

            if(j-i+1 == k){
                res = max(res, currSum);
                currSum -= arr[i];
                st.erase(arr[i]);
                i++;
            }
            j++;
        }

        return res;
    }
};