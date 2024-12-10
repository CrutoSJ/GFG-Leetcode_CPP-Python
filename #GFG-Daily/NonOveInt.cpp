// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1

// Date-> 10/12/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool func(vector<int> &a, vector<int> &b){
        if(a[1]<b[1])return true;
        else if(a[1]>b[1])return false;
        return a[0]<=b[0];
    }
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), func);
        int last=0, ans=0,n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<intervals[last][1])ans++;
            else last=i;
        }
        return ans;
    }
};