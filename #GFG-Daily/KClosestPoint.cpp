// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1

// Date-> 18/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void solve(vector<vector<int>>& points, int k, priority_queue<pair<int,pair<int,int>>> &max_heap){
        for(int i=0; i<points.size(); i++){
            int p1 = points[i][0];
            int p2 = points[i][1];
            int dist = p1 * p1 + p2 * p2;
            
            if(max_heap.size() < k){
                max_heap.push({dist,{p1,p2}});
            } else{
                auto top = max_heap.top();
                int distOld = top.first;
                if(dist<distOld){
                    max_heap.pop();
                    max_heap.push({dist,{p1,p2}});
                }
            }
        }
        return ;
    }
    
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> max_heap;
        solve(points, k, max_heap);
        vector<vector<int>> res;
        
        while(!max_heap.empty()){
            auto top = max_heap.top();
            max_heap.pop();
            int p1 = top.second.first;
            int p2 = top.second.second;
            
            res.push_back({p1,p2});
        }
        
        return res;
        
    }
};