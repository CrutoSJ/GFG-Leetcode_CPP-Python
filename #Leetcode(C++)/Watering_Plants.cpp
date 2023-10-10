// #Question:-

// You want to water n plants in your garden with a watering can. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i. There is a river at x = -1 that you can refill your watering can at.

// Each plant needs a specific amount of water. You will water the plants in the following way:

// Water the plants in order from left to right.
// After watering the current plant, if you do not have enough water to completely water the next plant, return to the river to fully refill the watering can.
// You cannot refill the watering can early.
// You are initially at the river (i.e., x = -1). It takes one step to move one unit on the x-axis.

// Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and an integer capacity representing the watering can capacity, return the number of steps needed to water all the plants.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0 , can = capacity;
        for(int i = 0 ; i<plants.size() ; i++)
        {
            if(can == capacity)
            {
                step =  step + (i+1);
                can = can - plants[i];
            }
            else if(can >= plants[i])
            {
                step =  step + 1;
                can = can - plants[i];
            }
            else 
            {
                step = step + i;
                i = i-1;
                can = capacity; //Filled up water
            }
        }
        return step;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n; 
        cout << "Enter the number of plants: ";
        cin >> n;

        vector<int> plants(n);
        cout << "Enter the watering needs for each plant: ";
        for(int i = 0; i < n; i++)
            cin >> plants[i];

        int capacity;  
        cout << "Enter the watering can capacity: ";
        cin >> capacity;

        Solution solution;
        int steps = solution.wateringPlants(plants, capacity);
        cout << "Steps needed to water all plants: " << steps << endl;
    }

    return 0;
}