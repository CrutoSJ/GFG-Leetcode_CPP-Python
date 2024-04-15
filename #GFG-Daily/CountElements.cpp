// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-the-elements1529/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        // Your code goes here;
        vector<int>ans;
        sort(b.begin(),b.end());
        
        for(int i=0; i<query.size(); i++){
            int index = query[i];
            int val = a[index];
            int cnt =upper_bound(b.begin(), b.end(), val)-b.begin();
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};