// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1

// Date-> 09/09/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int maxi = INT_MIN;
        for(int i=0;i<mices.size();i++){
            maxi = max(maxi, abs(mices[i]-holes[i]));
        }
        return maxi;
        
    }
};
