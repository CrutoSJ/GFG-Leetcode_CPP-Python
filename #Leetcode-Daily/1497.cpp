// #Question:-

// Link -> https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/?envType=daily-question&envId=2024-10-01

// Date -> 01/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        int n = arr.size();

        for(int i=0; i<n; i++){
            int rem = ((arr[i]%k) + k) % k;
            freq[rem]++;
        }

        if(freq[0] % 2 != 0){
            return false;
        }

        for(int i=1; i<=k/2; i++){
            int counter = k-i;
            if(freq[i] != freq[counter]){
                return false;
            }
        }

        return true;
    }
};