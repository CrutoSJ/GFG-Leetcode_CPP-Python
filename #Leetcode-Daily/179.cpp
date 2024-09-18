// #Question:-

// Link-> https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18

// Date-> 18/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comparator = [](int &a, int &b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            return s1+s2 > s2+s1;
        };

        sort(nums.begin(), nums.end(), comparator);

        if(nums[0] == 0){
            return "0";
        }

        string result = "";

        for(auto num : nums){
            result += to_string(num);
        }

        return result;
    }
};