// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/buy-stock-2/1

// Date-> 22/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int res = 0;
        int minVal = prices[0];
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>minVal){
                res = max(res,prices[i]-minVal);
            } else if(prices[i]<minVal){
                minVal = prices[i];
            }
        }
        
        return res;
    }
};