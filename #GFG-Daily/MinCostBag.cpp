#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(int n, int W, vector<int> &cost) {
        const int INF = 1e8;
        vector<int>prev(W + 1, INF);
        prev[0] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int w = 1; w <= W; w++){
                int take = INF, nottake = prev[w];
                if(i + 1 <= w && cost[i] != -1)
                    take = cost[i] + prev[w - (i + 1)];
                prev[w] = min(take, nottake);
            }
        }
    
        int ans = prev[W];
        if(ans >= INF)
            ans = -1;
        return ans;
    }
};