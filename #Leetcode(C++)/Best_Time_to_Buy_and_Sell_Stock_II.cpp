// #Question:-

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]-prices[i-1]>0)
                profit+=prices[i]-prices[i-1];
        }
        return profit;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    Solution sol;

    while(t--){
        int n;
        cout << "Enter the number of days: ";
        cin >> n;
        
        vector<int> prices(n);
        cout << "Enter the prices for each day:\n";
        for(int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        
        int max_profit = sol.maxProfit(prices);
        cout << "Maximum profit: " << max_profit << "\n";
    }
    
    return 0;
}