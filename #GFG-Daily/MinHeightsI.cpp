// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1

// Date-> 23/11/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        if(n==1)return 0;
        sort(arr.begin(), arr.end());
        int ans, mini, maxi;
        
        ans = arr[n-1]-arr[0];
        for(int i=1; i<n; i++){
            mini = min(arr[0]+k, arr[i]-k);
            maxi = max(arr[n-1]-k, arr[i-1]+k);
            ans  = min(ans, maxi-mini);
        }
        return ans;
    }
};