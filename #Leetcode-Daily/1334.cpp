// #Question:-

// Link-> https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=daily-question&envId=2024-07-26

// Date-> 26/07/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void FloydWar(int n, vector<vector<int>> &SPM){

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }


    int findResultCity(int n, vector<vector<int>> &SPM, int D){
        int resultCity = -1;
        int leastCityCount = INT_MAX;

        for(int i=0; i<n; i++){
            int CntLeast = 0;
            for(int j=0; j<n; j++){
                if(i!=j && SPM[i][j] <= D){
                    CntLeast++;
                }
            }

            if(CntLeast <= leastCityCount){
                leastCityCount = CntLeast;
                resultCity = i;
            }
        }

        return resultCity;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>SPM(n, vector<int>(n,1e9+7));

        for(int i=0; i<n; i++){
            SPM[i][i] = 0;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        FloydWar(n, SPM);

        return findResultCity(n, SPM, distanceThreshold);
    }
};