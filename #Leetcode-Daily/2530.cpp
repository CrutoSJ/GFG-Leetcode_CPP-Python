// #Question:-

// Link-> https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14

// Date-> 14/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<double> pq;
        long long score = 0;

        for(auto &num : nums){
            pq.push(num);
        }

        while(k--){
            double top = pq.top();
            pq.pop();
            score += top;
            pq.push(ceil(top/3));
        }
        return score;
    }
};