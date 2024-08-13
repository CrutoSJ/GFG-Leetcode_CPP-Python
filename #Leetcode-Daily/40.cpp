// #Question-:

// Link-> https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13

// Date-> 13/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int idx, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(temp);
            return ;
        }

        if(idx >= candidates.size() || target < 0){
            return ;
        }

        for(int i = idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            temp.push_back(candidates[i]);
            solve(i+1, candidates, target - candidates[i], temp, result);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result; 
        vector<int> temp;
        solve(0, candidates, target, temp, result);
        return result;
    }
};