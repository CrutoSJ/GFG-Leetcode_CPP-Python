// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1

// Date-> 04/11/24 && 28/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        unordered_map<int, vector<pair<int, int>>> mp;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                mp[sum].push_back({i, j});
            }
        }
        
        set<vector<int>> st;
        
        for (int i = 0; i < n; i++) {
            int target = -arr[i];
            
            if (mp.find(target) != mp.end()) {
                for (auto &idxPair : mp[target]) {
                    int j = idxPair.first;
                    int k = idxPair.second;
                    
                    if (i != j && i != k && j != k) {
                        vector<int> triplet = {i, j, k};
                        sort(triplet.begin(), triplet.end());
                        st.insert(triplet);
                    }
                }
            }
        }
        
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
