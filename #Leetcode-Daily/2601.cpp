// #Question:-

// Link-> https://leetcode.com/problems/prime-subtraction-operation/description/?envType=daily-question&envId=2024-11-11

// Date-> 11/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrime(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> previousPrime(maxElement + 1, 0);
        for (int i = 2; i <= maxElement; i++) {
            if (checkPrime(i)) {
                previousPrime[i] = i;
            } else {
                previousPrime[i] = previousPrime[i - 1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            int bound;
            if (i == 0) {
                bound = nums[0];
            } else {
                bound = nums[i] - nums[i - 1];
            }

            if (bound <= 0) {
                return 0;
            }

            int largestPrime = previousPrime[bound - 1];

            nums[i] = nums[i] - largestPrime;
        }
        return 1;
    }
};