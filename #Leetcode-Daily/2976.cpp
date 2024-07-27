// #Question:-

// Link-> https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27

// Date-> 27/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void FloydWar(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            adjMatrix[u][v] = min(adjMatrix[u][v], (long long)cost[i]);
        }

        for(int via=0; via<26; via++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adjMatrix(26, vector<long long>(26, INT_MAX));

        FloydWar(adjMatrix, original, changed, cost);

        long long ans = 0;

        for(int i=0; i<source.size(); i++){
            if(source[i] == target[i]){
                continue;
            }

            if(adjMatrix[source[i] - 'a'] [target[i] - 'a'] == INT_MAX){
                return -1;
            }

            ans += adjMatrix[source[i] - 'a'] [target[i] - 'a'];
        }

        return ans;
    }
};