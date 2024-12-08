// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

// Date-> 08/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            if(ans.empty() || ans.back()[1] < arr[i][0]){
                ans.push_back(arr[i]);
            } else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};