// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1

// Date-> 28/08/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class compare {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first)
                return a.first < b.first; 
            return a.second > b.second;
        };
};
    
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(auto &i : freq){
            pq.push({i.second, i.first});
        }
        vector<int>res;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int val = top.second;
            int cnt = top.first;
            while(cnt--){
                res.push_back(val);
            }
        }
        return res;
        
    }
};