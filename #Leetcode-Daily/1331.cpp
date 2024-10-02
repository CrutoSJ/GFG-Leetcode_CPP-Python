// #Question:-

// Link-> https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02

// Date-> 02/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> result;
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
        int rankNum = 1;

        for(int i=0; i<temp.size(); i++){
            if(rank.find(temp[i]) == rank.end()){
                rank[temp[i]] = rankNum;
                rankNum++;
            }
        }

        for(int i=0; i<arr.size(); i++){
            result.push_back(rank[arr[i]]);
        }

        return result;
    }
};