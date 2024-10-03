// #Question:-

// Link-> https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2024-10-03

// Date-> 03/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();

        for(auto &num : nums){
            sum = (sum + num) % p;
        }

        int extra = sum % p;

        if(extra == 0){
            return 0;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        int result = n;
        int curSum = 0;

        for(int i=0; i<n; i++){
            curSum = (curSum + nums[i]) % p;
            int target = (curSum - extra + p) % p;

            if(mp.find(target) != mp.end()){
                result = min(result, i-mp[target]);
            }

            mp[curSum] = i;
        }

        return result == n ? -1 : result;
    }
};