// #Question:-

// Link-> https://leetcode.com/problems/average-waiting-time/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int time = 0;
        double wTime = 0;
        for (double i = 0; i < n; i++) {
            if (customers[i][0] > time) {
                time = customers[i][0];
            }
            time += customers[i][1];
            wTime += time - customers[i][0];
        }
        return wTime / n;
    }
};
