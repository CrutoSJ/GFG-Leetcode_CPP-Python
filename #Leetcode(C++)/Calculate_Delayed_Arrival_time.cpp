// #Question:-

// You are given a positive integer arrivalTime denoting the arrival time of a train in hours, and another positive integer delayedTime denoting the amount of delay in hours.

// Return the time when the train will arrive at the station.

// Note that the time in this problem is in 24-hours format.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findDelayedArrivalTime(int arrival, int delay) {
        return (arrival+delay)%24;
    }
};

int main(){
    int t;
    cout << "Enter the no. of test cases: ";
    cin >> t;

    Solution sol;

    while(t--){
        int arrivalTime, delayedTime;
        cout << "Enter arrival time and delayed time (separated by space): ";
        cin >> arrivalTime >> delayedTime;

        int delayedArrivalTime = sol.findDelayedArrivalTime(arrivalTime, delayedTime);
        cout << "The train will arrive at the station at: " << delayedArrivalTime << " hours." << endl;
    }

    return 0;

}