// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

// Date-> 25/05/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        int mEle = *max_element(arr.begin(), arr.end());
        vector<int> vis(mEle+1, 0);
        
        for(int i=0; i<n; i++){
            vis[arr[i]] = 1;
        }
        
        for(int i=1; i<=mEle; i++){
            if(vis[i] == 0)continue;
            for(int j=1; j<=mEle; j++){
                if(vis[j] == 0)continue;
                int sum = i*i + j*j;
                int c = sqrt(sum);
                
                if(c*c != sum || c>mEle)continue;
                
                if(vis[c] == 1){
                    return true;
                }
            }
        }
        return false;
        
    }
};