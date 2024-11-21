// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

// Date-> 21/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int profit = 0;
        
        for(int i=1; i<n; i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};