// #Question:-

// Link-> https://leetcode.com/problems/count-number-of-nice-subarrays/

// Date-> 22/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ansCnt = 0;
        int cnt = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                k--;
                cnt = 0;
            }
            
            while (k == 0) {
                if (nums[i] % 2 != 0) {
                    k++;
                }
                cnt++;
                i++;
            }
            
            ansCnt += cnt;
            j++;
        }

        return ansCnt;
    }
};
