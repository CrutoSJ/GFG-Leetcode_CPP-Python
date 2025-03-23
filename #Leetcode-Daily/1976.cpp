// #Question:-

// Link-> https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/?envType=daily-question&envId=Invalid%20Date

// Date-> 23/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        typedef pair<long long, int> P;
        int M=1e9+7;
        int countPaths(int n, vector<vector<int>>& roads) {
            unordered_map<int, vector<pair<int,int>>> adj;
            for(auto &road : roads){
                int u = road[0];
                int v = road[1];
                int time = road[2];
    
                adj[u].push_back({v,time});
                adj[v].push_back({u,time});
            }
    
            priority_queue<P, vector<P>, greater<P>> pq;
            vector<long long> res(n, LLONG_MAX);
            vector<int> cnt(n,0);
    
            res[0]=0;
            cnt[0]=1;
            pq.push({0,0});
    
            while(!pq.empty()){
                long long curTime = pq.top().first;
                int curNode       = pq.top().second;
    
                pq.pop();
    
                for(auto &vec:adj[curNode]){
                    int nbr  = vec.first;
                    int time = vec.second;
    
                    if(curTime + time < res[nbr]){
                        res[nbr] = curTime + time;
                        pq.push({res[nbr],nbr});
                        cnt[nbr] = cnt[curNode];
                    } else if(curTime + time == res[nbr]){
                        cnt[nbr] = (cnt[nbr] + cnt[curNode])%M;
                    }
                }
            }
            return cnt[n-1];
        }
    };