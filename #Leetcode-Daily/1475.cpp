// #Question:-

// Date-> 18/12/24

// Link-> https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=daily-question&envId=2024-12-18

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            while (!stack.empty() && prices[stack.top()] >= prices[i]) {
                result[stack.top()] -= prices[i];
                stack.pop();
            }
            stack.push(i);
        }
        return result;
    }
};