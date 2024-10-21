// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/split-the-array0238/1

// Date-> 21/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int mod = 1e9+7;
        int val=0;
        int n = arr.size();
        for(int i=0; i<arr.size(); i++){
            val^=arr[i];
        }
        if(val!=0) return 0;
        int ans=1;
        for(int i=0; i<n-1; i++){
            ans=(ans*2)%mod;
        }
        return ans-1;
    }
};

