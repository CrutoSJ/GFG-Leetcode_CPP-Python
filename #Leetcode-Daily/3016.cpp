// #Question:-

// Link-> https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06

// Date-> 06/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(auto &i : word){
            freq[i]++;
        }

        priority_queue<int> maxHeap;
        for(auto &i : freq){
            maxHeap.push(i.second);
        }

        int push = 0;
        int cnt = 0;
        while(!maxHeap.empty()){
            int num = maxHeap.top();
            maxHeap.pop();

            int multiplier = cnt/8+1;
            push += multiplier*num;
            cnt++;
        }
        return push;
    }
};
