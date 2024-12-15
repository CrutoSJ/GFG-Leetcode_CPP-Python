// #Question:-

// Link-> https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15

// Date-> 15/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) - (double)passes / totalStudents;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]), {singleClass[0], singleClass[1]}});
        }

        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1), {passes + 1, totalStudents + 1}});
        }

        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }
        return totalPassRatio / classes.size();
    }
};