// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1

// Date-> 09/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        bool merged = false;
        int start = newInterval[0], end = newInterval[1];
        for(auto &x : intervals){
            if(x[1] < newInterval[0]){
                res.push_back(x);
            } else if(x[0] > newInterval[1]){
                if(!merged){
                    res.push_back({start,end});
                    merged = true;
                }
                res.push_back(x);
            } else{
                start = min(start,x[0]);
                end   = max(end  ,x[1]);
            }
        }
        if(!merged)res.push_back({start,end});
        return res;
    }
};