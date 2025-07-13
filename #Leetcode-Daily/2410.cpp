// #Question:-

// Link-> https://leetcode.com/problems/maximum-matching-of-players-with-trainers/submissions/1696488676/?envType=daily-question&envId=2025-07-13

// Date-> 13/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int m = players.size(), n = trainers.size();
        int count = 0;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            while (j < n && players[i] > trainers[j]) {
                j++;
            }
            if (j < n) {
                count++;
            }
        }
        return count;
    }
};