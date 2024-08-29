// #Question:-

// Link-> https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29

// Date-> 29/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int &n, int idx, vector<bool>&visited, vector<vector<int>>&stones)
    {
        visited[idx] = true;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                if(stones[idx][0] == stones[i][0])
                    dfs(n, i, visited, stones);

                if(stones[idx][1] == stones[i][1])
                    dfs(n, i, visited, stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        int group = 0;

        vector<bool>visited(n);
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(n, i, visited, stones);
                group += 1;
            }
        }
        return n - group;
    }
};