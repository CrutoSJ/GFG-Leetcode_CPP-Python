// #Question:-

// Link-> https://leetcode.com/problems/water-bottles/

// Date-> 07/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, drinkable = 0, empty = 0;
        while(numBottles>=numExchange){
            ans += drinkable;
            drinkable = numBottles/numExchange;
            empty = numBottles%numExchange;
            numBottles = empty+drinkable;
        }
        return ans+drinkable;
    }
};