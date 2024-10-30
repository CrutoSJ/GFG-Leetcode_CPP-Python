// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1

// Date-> 30/10/24

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        
        for(auto &x : arr){
            mp[x]++;
        }
        
        for(int i=0; i<arr.size(); i++){
            int target = k + arr[i];
            if(mp.find(target) != mp.end()){
                cnt += mp[target];
            }
        }
        
        return cnt;
    }
};