// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1

// Date -> 03/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> longestSubarray(vector<int>& arr, int x) {
            int n = arr.size();
            multiset<int> mt;
            int i = 0, j = 0;
            int maxLen = 0, startIdx = 0;
    
            while (j < n) {
                mt.insert(arr[j]);
    
                while (*mt.rbegin() - *mt.begin() > x) {
                    mt.erase(mt.find(arr[i]));
                    i++;
                }
    
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    startIdx = i;
                }
    
                j++;
            }
    
            vector<int> res(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
            return res;
        }
    };