// #Question:-

// Link-> https://leetcode.com/problems/ipo/

// Date-> 25/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n=p.size();
        vector<pair<int,int> >projects;
        for(int i=0; i<n; i++){
            projects.push_back({p[i],c[i]});
        }
        
        sort(projects.begin(),projects.end(),[](pair<int,int>a, pair<int,int>b){
            return a.second<b.second;
        });
        
        priority_queue<int>pq;
        
        int i=0;
        
        while(k--){
            while(i<n && projects[i].second<=w){
                pq.push(projects[i++].first);
            }
            
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};