// #question:-

// A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

// The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

// For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
// Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{ 
    public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int i = n-1, ans = 0;
        
        if(n <= 2){
            for(auto x: cost) 
                ans += x;
            return ans;
        }
        
        sort(cost.begin(), cost.end());
        
        while(i>=1){
            ans += cost[i] + cost[i-1];
            if(i-1 == 0 || i-1 == 1) return ans;
            i = i-3;
        }
        ans += cost[0];
        
        return ans;
    }

};

int main(){
    int t;
    cout << "Enter the value of t: ";
    cin >> t;
    while(t--){
        while (t--) {
        int n;
        cout << "Enter the number of candies: ";
        cin >> n;

        vector<int> cost(n);
        cout << "Enter the cost of each candy: ";
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }

        Solution obj;
        int minimumCost = obj.minimumCost(cost);
        cout << "Minimum cost of buying all the candies: " << minimumCost << endl;
    }

    return 0;
    }
}