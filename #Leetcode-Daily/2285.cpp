// #Question:-

// Link-> https://leetcode.com/problems/maximum-total-importance-of-roads/

// Date-> 28/06/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);
        for(auto i : roads){
            int a=i[0];
            int b=i[1];
            
            degree[a]++;
            degree[b]++;
        }
        sort(degree.begin(), degree.end());
        long long sum=0, m=1;
        for(int i=0; i<n; i++){
            long long val = degree[i]*m;
            sum += val;
            m++;
        }
        return sum;
    }
};