// #Question:-

// It is a sweltering summer day, and a boy wants to buy some ice cream bars.

// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

// Note: The boy can buy the ice cream bars in any order.

// Return the maximum number of ice cream bars the boy can buy with coins coins.

// You must solve the problem by counting sort.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            if(costs[i]>coins)break;
            coins -= costs[i];
            count++;
        }
        return count;
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    while(t--){
        int n, coins;
        cout << "Enter number of ice cream bars and coins: ";
        cin >> n >> coins;

        vector<int> costs(n);
        cout << "Enter the costs of ice cream bars: ";
        for(int i = 0; i < n; i++){
            cin >> costs[i];
        }

        Solution solution;
        int maxIceCreamBars = solution.maxIceCream(costs, coins);
        cout << "Maximum ice cream bars: " << maxIceCreamBars << endl;
    }

    return 0;
}