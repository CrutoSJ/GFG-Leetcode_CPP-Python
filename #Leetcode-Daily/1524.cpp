// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

// Date-> 25/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            int count = 0, prefixSum = 0;
            int oddCount = 0, evenCount = 1;
    
            for (int num : arr) {
                prefixSum += num;
                if (prefixSum % 2 == 0) {
                    count += oddCount;
                    evenCount++;
                } else {
                    count += evenCount;
                    oddCount++;
                }
    
                count %= MOD;
            }
    
            return count;
        }
    };