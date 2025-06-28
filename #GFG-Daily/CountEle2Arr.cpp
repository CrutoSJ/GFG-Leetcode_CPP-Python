// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1

// Date-> 28/06/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution_prefixSum {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> freq(1e5+1,0);
        
        for(int &val : b){
            freq[val]++;
        }
        
        vector<int> preSum(1e5+1);
        preSum[0] = freq[0];
        
        for(int i=1; i<=1e5; i++){
            preSum[i] = preSum[i-1] + freq[i];
        }
        
        vector<int> res(n,0);
        
        for(int i=0; i<n; i++){
            res[i] = preSum[a[i]];
        }
        
        return res;
    }
};

class Solution_upperBound {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();
        sort(b.begin(), b.end());
        
        vector<int> res(n,0);
        
        for(int i=0; i<n; i++){
            int cnt = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            res[i] = cnt;
        }
        
        return res;
    }
};