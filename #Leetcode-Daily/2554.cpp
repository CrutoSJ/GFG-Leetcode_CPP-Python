// #Question:-

// Link-> https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/?envType=daily-question&envId=2024-12-06

// Date-> 06/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        int currSum = 0, cnt = 1, res = 0;

        for(int &num : banned){
            st.insert(num);
        }

        while(cnt<=n && currSum <= maxSum){
            if(st.find(cnt) == st.end() && currSum+cnt<=maxSum){
                res++;
                currSum += cnt;
            }
            cnt++;
        }
        return res;
    }
};