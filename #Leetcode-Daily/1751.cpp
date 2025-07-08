// #Question:-

// Link-> https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/?envType=daily-question&envId=2025-07-08

// Date-> 08/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
vector<vector<int>> t;
int solve(vector<vector<int>>& events, int i, int k){
    if(i>=n || k==0){
        return 0;
    }
    if(t[i][k] != -1){
        return t[i][k];
    }   
    int start=events[i][0];
    int end=events[i][1];
    int value=events[i][2];
    int skip=solve(events, i+1, k);
    int j = i+1;
    for(;j<n;j++){
        if(events[j][0]>events[i][1]){
            break;
        }
    }
    int take = value+solve(events,j,k-1);
    return t[i][k]=max(skip,take);
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        n=events.size();
        t.resize(n+1,vector<int>(k+1,-1));
        return solve(events,0,k);
    }
}; 

