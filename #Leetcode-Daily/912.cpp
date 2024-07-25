// #Question:-

// Link-> https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25

// Date-> 25/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>minHeap;

        for(int i=0; i<nums.size(); i++){
            minHeap.push(nums[i]);
        }
        int i=0;
        while(!minHeap.empty()){
            nums[i]=minHeap.top();
            minHeap.pop();
            i++;
        }
        return nums;
    }
};