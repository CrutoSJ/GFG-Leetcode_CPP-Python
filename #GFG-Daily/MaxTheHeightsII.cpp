// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

// Date-> 17/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int big   = arr[n-1];
        int small = arr[0];
        
        int ans = (big-small);
        
        for(int i=1; i<n; i++){
            big   = max(arr[n-1] - k, arr[i-1] + k);
            small = min(arr[0] + k, arr[i] - k);
            if(small<0){
                continue;
            }
            ans = min(ans, big - small);
        }
        return ans;
    }
};