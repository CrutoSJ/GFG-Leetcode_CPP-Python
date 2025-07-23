// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1

// Date-> 23/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long)arr[i] * (i + 1) * (n - i);
        }
        return (int)res;
    }
};

class Solution2 { //O(n^2) approach
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        vector<int> cuSum(n, 0);
        cuSum[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            cuSum[i] = cuSum[i - 1] + arr[i];
        }

        int res = 0;
        int i = 0, j = 0;

        while (i < n) {
            j = i;
            while (j < n) {
                int currSum = cuSum[j] - (i > 0 ? cuSum[i - 1] : 0);
                res += currSum;
                j++;
            }
            i++;
        }
        return res;
    }
};