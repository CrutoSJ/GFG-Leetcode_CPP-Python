// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

// Date-> 10/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        const int n = arr.size();
        std::vector<int> m(n + 2, 1e9);
        m[0] = -1;

        int ans = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > k) {
                ++b;
            }
            else {
                --b;
            }
            
            if (b > 0) {
                ans = i + 1;
            }
            else {
                m[-b] = std::min(m[-b], i);
                ans = std::max(ans, i - m[-b + 1]);
            }
        }
        
        return ans;
        
    }
};