// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1

// Date-> 24/07/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res=0;
        
        for(int i=0; i<left.size(); i++){
            res = max(res, left[i]);
        }
        
        for(int i=0; i<right.size(); i++){
            res = max(res, n-right[i]);
        }
        
        return res;
    }
};
