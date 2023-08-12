// #Question:-

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for(int i=2; i<n; i++){
            cost[i] = min(cost[i-1],cost[i-2]) + cost[i];
        }

        return min(cost[n-1],cost[n-2]);
    }
};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of steps: ";
        cin >> n;

        vector<int> cost(n);
        cout << "Enter the cost for each step: ";
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }

        Solution solution;
        int minCost = solution.minCostClimbingStairs(cost);
        cout << "Minimum cost to reach the top: " << minCost << endl;
    }

    return 0;


}