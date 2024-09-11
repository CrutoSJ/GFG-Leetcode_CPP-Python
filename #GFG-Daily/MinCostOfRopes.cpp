// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// Date-> 11/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long , vector<long long>, greater<long long>> minHeap;
        for(auto &x : arr){
            minHeap.push(x);
        }
        long long cost = 0;
        while(minHeap.size()>1){
            long long num1 = minHeap.top();
            minHeap.pop();
            long long num2 = minHeap.top();
            minHeap.pop();
            
            long long sum = num1+num2;
            cost += sum;
            minHeap.push(sum);
        }
        
        return cost;
    }
};