// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

// Date-> 16/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        unordered_map<int, int> mp;
        queue<pair<int, int>> q;
        int ans = INT_MAX;
        vector<int> v = {-1, -1};
        
        int row = arr.size();
        int col = arr[0].size();
        for (int i = 0; i < row; i++){
            pq.push({arr[i][0], {i, 0}});
        }
        
        while (!pq.empty()){
            int min_val = pq.top().first;
            int min_index_row = pq.top().second.first;
            int min_index_col = pq.top().second.second;
            
            pq.pop();
            if (min_index_col + 1 < col) {
                pq.push({arr[min_index_row][min_index_col + 1], {min_index_row, min_index_col + 1}});
            }
            
            q.push({min_val, min_index_row});
            mp[min_index_row]++;
            while (mp.size() == row){
                if (ans > (q.back().first - q.front().first)){
                    v = {q.front().first, q.back().first};
                    ans = q.back().first - q.front().first;
                }
                
                int start = q.front().first;
                int index_row = q.front().second;
                q.pop();
                mp[index_row]--;
                if (mp[index_row] == 0) {
                    mp.erase(index_row);
                }
            }
        }
        
        return v;
        
    }
};