// #Question:-

// Link-> https://leetcode.com/problems/find-the-maximum-sum-of-node-values/?envType=daily-question&envId=2025-05-23

// Date-> 23/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum  = 0;
        int cnt = 0;
        int sub = INT_MAX;

        for(ll num:nums){
            if((num^k) > num){
                cnt+=1;
                sum+=(num^k);
            } else{
                sum += num;
            }

            sub = min((ll)sub, abs(num-(num^k)));
        }

        if(cnt%2 == 0){
            return sum;
        }

        return sum-sub;
    }
};