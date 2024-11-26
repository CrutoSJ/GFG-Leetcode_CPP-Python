// #Question:-

// Link-> https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26

// Date-> 26/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

        for(auto &edge : edges){
            int v = edge[1];
            indegree[v]++;
        }

        int champ = -1, cnt = 0;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                champ = i;
                cnt++;
                if(cnt>1){
                    return -1;
                }
            }
        }
        return champ;
    }
};